#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*array;

	if (argc_ctl(argc, argv) == 0)
		free_and_exit(NULL, 1, 0);
	array = stack_init(argc, argv);
	itoa_index_array(array->arr, array->a_sz);
	radix_decimal_sort(array);
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
			if(!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
