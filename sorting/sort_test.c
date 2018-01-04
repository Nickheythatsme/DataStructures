#include "sort_test.h"

/* FDT for sorting functions and the number of functions in list */
const struct sort_table sort_funcs[]  =
{
    /* name      type     func */
    {"bubble" , SORTING, bubble },
    {"quick"  , SORTING, quick  }
};
const size_t num_sort_funcs = sizeof(sort_funcs) / sizeof(struct sort_table);

/* Display function which formats and displays all elements in the array */
int
display(int *array, size_t len)
{
    size_t i = 0;
    size_t row_len = 0;

    for(; i < len; ++i)
    {
        printf("%3d, ", array[i]);
        ++row_len;
        if(row_len > 10)
        {
            printf("\n");
            row_len = 0;
        }
    }
    printf("\n");

    return 1;
}

/* Shuffle the array with Fischer Yates shuffle */
int
shuffle(int *array, size_t len)
{
    srand(clock());

    int i = 0;
    size_t place;
    int temp;

    for(; i < len; ++i)
    {
        place = rand() % len;
        temp = array[i];
        array[i] = array[place];
        array[place] = temp;
    }

    return len;
}

/* Run a test as specified by the a_test struct */
unsigned long
run_test(struct a_test *to_run)
{
    struct timeval tf, ti;
    unsigned long timems=0;
    int *array;
    int i;

    /* Make the sorted array */
    array = (int*) malloc( to_run -> length * sizeof(int) );
    for(i = 0; i < to_run -> length; ++i)
    {
        array[i] = i;
    }

    gettimeofday(&ti, NULL);
    for(i = 0; i < to_run -> iterations; ++i)
    {
        /* Shuffle the array if needed */
        if(to_run -> do_shuffle)
        {
            shuffle(array, to_run -> length);
        }

        /* Call sorting functions and record time */
        to_run -> func -> func(array, to_run -> length);
    }
    gettimeofday(&tf, NULL);

    /* Display the sorted array if indicated */
    if(to_run -> do_display_array)
    {
        display(array, to_run -> length);
    }

    /* Calculate ms */
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+tf.tv_usec/1000);

    /* Display the stats if indicated */
    if(to_run -> do_display_stats)
    {
        /* Display sorting stats */
        printf("Length: %lu\n"
                "Iterations: %lu\n"
                "Time (ms): %lu\n"
                "Sort: %s\n"
                "Shuffled: %d\n",
                to_run -> length, 
                to_run -> iterations,
                timems,
                to_run -> func -> name,
                to_run -> do_shuffle
                );
    }

    free(array);

    return timems;
}


int
main(int argc, char **argv)
{
    int i;
    struct a_test to_run;

    if(argc != 3)
    {
        printf("Usage: ./[exec] [array length] [iterations]\n");
        exit(EXIT_FAILURE);
    }

    /* Find the length of the array and the number of iterations */
    sscanf(argv[1],"%lu",&to_run.length);
    sscanf(argv[2],"%lu",&to_run.iterations);

    /* Set some config values for the tests */
    to_run.do_display_stats = 1;
    to_run.do_display_array = 0;
    to_run.do_shuffle       = 1;

    for(i=0; i < num_sort_funcs; ++i)
    {
        to_run.func = &sort_funcs[i];
        run_test(&to_run);
    }

    return 0;

}

