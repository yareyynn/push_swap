/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarensakarya <yarensakarya@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:11:00 by ysakarya          #+#    #+#             */
/*   Updated: 2025/04/16 23:18:23 by yarensakary      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_array(int argc, char **argv, t_stack *array)
{
	int		i;
	int		j;
	int		k;
	char	**numbers;

	array->arr_b = malloc(sizeof(long) * (array->size));
	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		numbers = ft_split(argv[i++], ' ');
		while (numbers[j])
			array->arr_b[k++] = ft_atoi(numbers[j++]);
		free_split(numbers);
		j = 0;
	}
	is_unique(array);
	is_sorted(array);
	array->arr_a = malloc(sizeof(long) * array->size);
	index_elements(array);
}

void	is_unique(t_stack *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (array->arr_b[i] == array->arr_b[j])
			{
				free(array->arr_b);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	is_sorted(t_stack *array)
{
	int	i;

	i = 0;
	while (i < array->size - 1)
	{
		if (array->arr_b[i] > array->arr_b[i + 1])
			return ;
		i++;
	}
	free(array->arr_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
