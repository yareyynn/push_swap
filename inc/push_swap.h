#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long	*arr_a;
	long	*arr_b;
	char	**temp;
	int		a_st;
	int		b_st;
	int		a_sz;
	int		b_sz;
	int		size;
	int 	bit;
}	t_stack;

void	arg_ctl(int argc, char **argv);
void	arg_check(int argc, char **argv);
void	space_check(int argc, char **argv);
t_stack	stack_init(int argc, char **argv);
void	split_check(t_stack array);
void	array_init(t_stack array, int size);
void	array_check(t_stack array);
void	is_sorted(t_stack array);
void	is_unique(t_stack array);
void	free_and_exit(t_stack array, int i, int f);
void	radix_sort(t_stack array);
void	index_elements(t_stack array);
void	pa(t_stack array);
void	pb(t_stack array);
void	ra(t_stack array);
void	rb(t_stack array);

# endif
