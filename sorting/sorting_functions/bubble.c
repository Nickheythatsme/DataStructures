#include <stdio.h>
#include <stdlib.h>

/* 
 * Implementation of bubble sort 
 * */
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

