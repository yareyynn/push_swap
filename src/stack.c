/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:53:47 by ysakarya          #+#    #+#             */
/*   Updated: 2025/04/17 03:17:04 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	char_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '\0'
				|| (argv[i][j] != '-' && argv[i][j] != '+'
				&& argv[i][j] != ' ' && !ft_isdigit(argv[i][j])))
				error_exit();
			j++;
		}
		i++;
	}
}

void	space_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (argv[i][j] == '\0')
			error_exit();
		i++;
	}
}

int	check_args(int argc, char **argv)
{
	char	**split;
	int		i ;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit();
		j = -1;
		while (split[++j])
		{
			if (!is_valid_number(split[j]) || !check_limits(split[j]))
			{
				free_split(split);
				error_exit();
			}
			c++;
		}
		free_split(split);
	}
	return (c);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(char *str)
{
	long	num;
	char	c;
	int		i;

	i = 0;
	c = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		c++;
	}
	while (str[i] == '0')
	{
		i++;
		c++;
	}
	if (ft_strlen(str) - c > 10)
		return (0);
	num = ft_atol(str);
	if (num < MIN_INT || num > MAX_INT)
		return (0);
	return (1);
}
