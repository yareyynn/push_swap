#include "../inc/push_swap.h"

void	free_and_exit(t_stack array, int i, int f)
{
	if (array.temp)
	{
		while (array.temp[i])
		{
			free(array.temp[i]);
			i++;
		}
		free(array.temp);
	}
	if (array.arr_a)
		free(array.arr_a);
	if (array.arr_b)
		free(array.arr_b);
	if (f == 1)
		write(2, "Error\n", 6);
	exit(f);
}
