#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int *a;
	int *b;
}	t_stack;


int argc_ctl(int argc, void *argv);
t_stack *stack_init(int argc, void *argv);
int check_sorted(t_stack *array);
int check_sorted_rev(int *arr, int size);
int check_duplicates(int *arr, int size);

# endif
