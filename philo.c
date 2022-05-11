/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:09:39 by sergejleski       #+#    #+#             */
/*   Updated: 2022/03/05 02:09:40 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork_and_philo_1(t_data *p)
{
	int	i;

	p->philo = malloc(sizeof(t_philo) * p->n_philo);
	i = -1;
	while (++i < p->n_philo)
	{
		p->philo[i].link = p;
		p->philo[i].n = i + 1;
		p->philo[i].right = i;
		if (i == p->n_philo - 1)
			p->philo[i].left = 0;
		else
			p->philo[i].left = i + 1;
		p->philo[i].t_eat = 0;
		p->philo[i].set_time = get_time();
	}
}

void	init_fork_and_philo(t_data *p)
{
	int	i;

	i = -1;
	p->fork = malloc(sizeof(pthread_mutex_t) * p->n_philo);
	while (++i < p->n_philo)
		pthread_mutex_init(&p->fork[i], NULL);
	init_fork_and_philo_1(p);
}

int	get_arg(t_data *info, int argc, char **argv)
{
	info->n_philo = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	if (info->n_philo <= 0 || info->die <= 0
		|| info->eat <= 0 || info->sleep <= 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*info;

	info = malloc(sizeof(t_data));
	memset(info, 0, sizeof(t_data));
	if ((argc != 5 && argc != 6 && !info) || !get_arg(info, argc, argv))
	{
		free (info);
		return (0);
	}
	info->start = get_time();
	init_fork_and_philo(info);
	create_thread(info);
	free(info->philo);
	free(info->fork);
	free(info);
	return (0);
}
