/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:09:48 by sergejleski       #+#    #+#             */
/*   Updated: 2022/03/05 02:09:49 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static void	skip_space(const char *str, int *i, int *n)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		++*i;
	if (str[*i] == '-')
	{
		*n = -(*n);
		++*i;
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
	if (str[*i] == '+')
	{
		++*i;
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
}

static void	check_dit(const char *str, int *i)
{
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		++*i;
	}
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			n;
	long int	res;

	i = 0;
	n = 1;
	res = 0;
	skip_space(str, &i, &n);
	j = i;
	check_dit(str, &i);
	while (str[j] >= '0' && str [j] <= '9')
	{
		res = res * 10 + str[j] - '0';
		j++;
		if (res * n > 2147483647 || res * n < -2147483648)
			exit(1);
	}
	return (res * n);
}
