#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long	*arr;
	char **temp;
	int a_sz;
	int b_sz;
	int a_st;
	int b_st;
	char **index_str;
}	t_stack;

int argc_ctl(int argc, char **argv);
t_stack *stack_init(int argc, char **argv);
int split_check(t_stack *array);
void array_init(t_stack *array, int size);
void array_check(t_stack *array);
int is_sorted(t_stack *array);
int is_unique(t_stack *array);
void free_and_exit(t_stack *array, int f, int i);
void radix_sort(t_stack *array);
void pa(t_stack *array);
void pb(t_stack *array);
void ra(t_stack *array);
void rb(t_stack *array);
int count_digits(int n);
char **itoa_index_array(long *arr, int size);
void radix_decimal_sort(t_stack *s);

# endif
