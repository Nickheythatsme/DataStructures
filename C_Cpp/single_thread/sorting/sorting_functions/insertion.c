#include <stdio.h>
#include <stdlib.h>

struct value
{
    int v;
    struct value *next;
};

/*
 * Inserts a new value into the LLL. Creates a new node as well 
 */
int
insert_LLL(struct value **head, int new_value)
{
    struct value *new_node;

    /* If head doesn't exist we need to make it */
    if(!*head)
    {
        *head = (struct value*) malloc(sizeof(struct value));
        (*head) -> v = new_value;
        (*head) -> next = NULL;
        return 1;
    }

    /* If new_value is higher than us, keep going. */
    if( (*head) -> v < new_value)
    {
        return insert_LLL(&((*head) -> next), new_value);
    }

    /* If we're higher than new_value then we need to change head and put
     * the new node in our place and shift us up */
    /* if ( (*head) -> v > new_value) */
    new_node = (struct value*) malloc(sizeof(struct value));
    new_node -> v = new_value;
    new_node -> next = (*head);
    *head = new_node;
    return 1;
}


/*
 * Implementation of the insertion sort
 */
int
insertion(int *array, size_t len)
{
    struct value *head, *temp;
    int i;

    head = (struct value*) malloc(sizeof(struct value));
    temp = head;
    head -> v = array[0];
    head -> next = NULL;

    for(i = 1; i < len; ++i)
        insert_LLL(&(head), array[i]);

    for(i = 0; i < len; ++i)
    {
        array[i] = head -> v;
        temp = head;
        head = head -> next;
        free(temp);
    }

    return 1;
}

