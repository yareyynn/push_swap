/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:14:26 by ysakarya          #+#    #+#             */
/*   Updated: 2025/04/17 01:20:26 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	array;

	array.size = stack_init(argc, argv);
	get_array(argc, argv, &array);
	array.a_st = 0;
	array.b_st = 0;
	array.a_sz = array.size;
	array.b_sz = 0;
	if (array.size != 5 && array.size != 3 && array.size != 2)
		radix_sort(&array);
	else if (array.size == 5)
		five_sort(&array);
	else if (array.size == 3 || array.size == 2)
		little_sort(&array, 0);
	free(array.arr_a);
	free(array.arr_b);
}

int	stack_init(int argc, char **argv)
{
	char_check(argc, argv);
	space_check(argc, argv);
	return (check_args(argc, argv));
}
