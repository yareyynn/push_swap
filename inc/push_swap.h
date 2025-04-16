/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:30:29 by ysakarya          #+#    #+#             */
/*   Updated: 2025/04/16 04:04:11 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

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
	int		bit;
}	t_stack;

int		stack_init(int argc, char **argv);
void	char_check(int argc, char **argv);
void	space_check(int argc, char **argv);
int		check_args(int argc, char **argv);
int		is_valid_number(char *str);
int		check_limits(char *str);
void	get_array(int argc, char **argv, t_stack *array);
void	is_unique(t_stack *array);
void	is_sorted(t_stack *array);
void	index_elements(t_stack *array);
void	free_split(char **temp);
void	error_exit(void);
void	radix_sort(t_stack *array);
void	push_back_sorted(t_stack *array, int bit);
void	five_sort(t_stack *array);
void	little_sort(t_stack *array);
void	pa(t_stack *array);
void	pb(t_stack *array);
void	ra(t_stack *array);
void	rb(t_stack *array);

#endif
