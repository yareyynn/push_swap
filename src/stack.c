#include "../inc/push_swap.h"

t_stack stack_init(int argc, char **argv)
{
	t_stack array;
	char **numbers;
	int i;

	arg_check(argc, argv);
	space_check(argc, argv);
	
	
}

void arg_check(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		free_and_exit((t_stack){0}, 0, 1);
	i = 1;
	while (i < argc)
	{
		while (argv[i][j])
		{
			j = 0;
			if (argv[i][0] == NULL
				|| argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ' && !ft_isdigit(argv[i][j]))
				free_and_exit((t_stack){0}, 0, 1);
			j++;
		}
		i++;
	}
}

void	space_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (argv[i][j] == '\0')
			free_and_exit((t_stack){0}, 0, 1);
		i++;
		j = 0;
	}
}
