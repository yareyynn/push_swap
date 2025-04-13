#include "../inc/push_swap.h"

void free_and_exit(t_stack *array, int f, int i)
{
    if (array->arr)
        free(array->arr);
    if (array->temp)
    {
        while(array->temp[i])
        {
            free(array->temp[i]);
            i++;
        }
        free(array->temp);
    }
    if(array)
        free(array);
    if(f == 1)
    {
        ft_printf("Error\n");
        exit(1);
    }
    else if (f == 0)
        exit(0);
}
