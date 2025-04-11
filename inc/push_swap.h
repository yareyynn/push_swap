#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int a_sz;
	int b_sz;
	int a_st;
	int b_st;
	int max;
	int min;
}	t_stack;

int argc_ctl(int argc, char **argv);
t_stack *stack_init(int argc, void *argv);
int check_sorted(t_stack *array);
int check_sorted_rev(int *arr, int size);
int check_duplicates(int *arr, int size);
void pa(t_stack *array);
void pb(t_stack *array);
void ra(t_stack *array);
void rb(t_stack *array);
void radix_sort(t_stack *array);
void get_max_min(t_stack *array);

# endif
