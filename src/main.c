#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*array;

	if (argc_ctl(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	array = stack_init(argc, argv);
	if(check_sorted(array) == 1)
	{
		free(array->arr);
		free(array);
		return (0);
	}
	if (check_duplicates(array->arr, array->a_sz) == 0)
	{
		write(2, "Error\n", 6);
		free(array->arr);
		free(array);
		return (1);
	}
	radix_sort(array);
}

int argc_ctl(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		return (0);
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
