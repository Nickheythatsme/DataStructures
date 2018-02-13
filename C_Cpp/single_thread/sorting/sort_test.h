#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

/* Define FDT for sorting functions */
#define SORTING 100
#define SUPPORT 101

typedef int sort_func(int *array, size_t len);

struct sort_table
{
    char *name;
    int type;
    sort_func *func;
};

struct a_test
{
    size_t length;
    size_t iterations;
    char do_shuffle;
    char do_display_array;
    char do_display_stats;
    const struct sort_table *func;
};

/* Forward declaration of functions */
extern       sort_func          bubble, quick, insertion, merge;
extern const size_t             num_sort_funcs;
extern const struct sort_table  sort_funcs[];
