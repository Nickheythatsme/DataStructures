#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Implementation of bubble sort */
    int
bubble(int *array, size_t len)
{
    int temp;
    size_t i = 0;
    size_t j = 0;

    for(;i < len; ++i)
    {
        j = i+1;
        for(;j < len; ++j)
        {
            if(array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return 1;
}

/* Implementation of the quick sort */
/* Recursive quick sort for one iteration through the array.
 * Returns the new sorted_index value */
int
_quick(int *array, int first, int last)
{
    int i, j, pivot, temp;

    if(first < last){
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(array[i] <= array[pivot] && i < last)
                i++;
            while(array[j] > array[pivot])
                j--;
            if(i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        _quick(array, first, j-1);
        _quick(array, j+1, last);

    }
    return 1;
}

/* Wrapper for quicksort */
int
quick(int *array, size_t len)
{
    /* Indicates the index to which all values are sorted, and beyond which
     * values have yet to be sorted (inclusive) */
    int sorted_index = 0;

    sorted_index = _quick(array, 0, len-1);

    return 1;
}

