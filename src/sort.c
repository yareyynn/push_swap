/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:20:49 by ysakarya          #+#    #+#             */
/*   Updated: 2025/04/16 05:01:48 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	index_elements(t_stack *array)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	while (++i < array->size)
	{
		j = -1;
		index = 0;
		while (++j < array->size)
		{
			if (array->arr_b[i] > array->arr_b[j])
				index++;
		}
		array->arr_a[i] = index;
	}
	i--;
	j = 0;
	while ((i >> j) != 0)
		j++;
	array->bit = j;
}

void	radix_sort(t_stack *array)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	while (i < array->bit)
	{
		j = 0;
		m = array->a_sz;
		while (j < m)
		{
			if ((array->arr_a[array->a_st] >> i) & 1)
				ra(array);
			else
				pb(array);
			j++;
		}
		i++;
		push_back_sorted(array, i);
	}
	free(array->arr_b);
	free(array->arr_a);
}

void	push_back_sorted(t_stack *array, int bit)
{
	int	j;
	int	m;

	j = 0;
	m = array->b_sz;
	while (j < m)
	{
		if (((array->arr_b[array->b_st] >> bit) & 1))
			pa(array);
		else
			rb(array);
		j++;
	}
}

void	little_sort(t_stack *array)
{
	if (array->size == 2)
	{
		if (array->arr_a[0] > array->arr_a[1])
			ra(array);
	}
	else if (array->size == 3)
	{
		if (array->arr_a[0] == 0 && array->arr_a[1] == 2)
			write(1, "ra\nsa\n", 8);
		else if (array->arr_a[0] == 1 && array->arr_a[1] == 0)
			write(1, "sa\n", 3);
		else if (array->arr_a[0] == 1 && array->arr_a[1] == 2)
			write(1, "rra\n", 4);
		else if (array->arr_a[0] == 2 && array->arr_a[1] == 1)
			write(1, "rra\nsa\n", 8);
		else if (array->arr_a[0] == 2 && array->arr_a[1] == 0)
			write(1, "ra\n", 3);
	}
}

void	five_sort(t_stack *array)
{
	int i;

	i = 0;
	while (i < array->size)
	{
		if (array->arr_a[i] == 0 || array->arr_a[i] == 1)
			pb(array);
			
		else
			ra(array);
		i++;
	}
	little_sort(array);
	if(array->arr_b[0] > array->arr_b[1])
		write(1, "sb\n", 3);
	write(1, "pa\npa\n", 6);
}
