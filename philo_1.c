/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:09:07 by sergejleski       #+#    #+#             */
/*   Updated: 2022/03/05 02:20:27 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned int time_to_wait)
{
	unsigned long	time;

	time = get_time();
	while (get_time() < time + (unsigned long)time_to_wait)
		usleep(100);
}

void	*live(void	*p)
{
	t_philo	*new_p;

	new_p = (t_philo *)p;
	while (!new_p->link->flag)
	{
		take_f_e(new_p);
		if (new_p->t_eat != new_p->link->must_eat)
		{
			print(p, "is sleeping\n");
			ft_usleep(new_p->link->sleep);
			print(p, "is thinking\n");
		}
		new_p->t_eat++;
	}
	return (NULL);
}

void	create_thread(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->n_philo)
	{
		p->philo[i].set_time = get_time();
		pthread_create(&p->philo[i].thread,
			NULL, live, &p->philo[i]);
		i += 2;
		ft_usleep(100);
	}
	i = 1;
	while (i < p->n_philo)
	{
		p->philo[i].set_time = get_time();
		pthread_create(&p->philo[i].thread,
			NULL, live, &p->philo[i]);
		i += 2;
		ft_usleep(100);
	}
	check(p);
	end(p);
}
