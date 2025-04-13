#include "../inc/push_swap.h"

t_stack *stack_init(int argc, char **argv)
{
    t_stack *array;
    int i;
    (void)argc;

    i = 0;
    array = malloc(sizeof(t_stack));
    if (!array)
        return (NULL);
    array->temp = ft_split(argv[1], ' ');
    if (!array->temp)
    {
        free(array);
        return (NULL);
    }
    i += split_check(array);
    array->arr = malloc(sizeof(int) * i * 3);
    if (!array->arr)
    {
        free(array->temp);
        free(array);
        return (NULL);
    }
    array_check(array);
    return (array);
}

int split_check(t_stack *array)
{
	int i;
	int j;

	i = 0;
	while (array->temp[i])
	{
		j = 0;
		while (array->temp[i][j])
		{
			if ((array->temp[i][j] == '-' || array->temp[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(array->temp[i][j]) || j > 11)
				free_and_exit(array, 1, 0);
			j++;
		}
		i++;
	}
	return (i);
}


void array_check(t_stack *array)
{
    int i;

    i = 0;
    while (array->temp[i])
    {
        array->arr[i] = ft_atol(array->temp[i]);
        if (array->arr[i] > 2147483647 || array->arr[i] < -2147483648 || !is_unique(array))
            free_and_exit(array, 1, i);
        free(array->temp[i]);
        i++;
    }
    free(array->temp);
    array->a_sz = i;
    array->b_sz = 0;
    array->a_st = 0;
    array->b_st = 2 * i - 1;
    is_sorted(array);
}

int is_unique(t_stack *array)
{
    int i;
    int j;

    i = 0;
    while (i < array->a_sz)
    {
        j = i + 1;
        while (j < array->a_sz)
        {
            if (array->arr[i] == array->arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_sorted(t_stack *array)
{
    int i;

    i = 0;
    while (i < array->a_sz - 1)
    {
        if (array->arr[i] > array->arr[i + 1])
            return (0);
        i++;
    }
    free_and_exit(array, 0, 0);
    return (1);
}
