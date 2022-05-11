/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:08:27 by sergejleski       #+#    #+#             */
/*   Updated: 2022/03/05 02:08:29 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	int				n;
	int				t_eat;
	unsigned long	set_time;
	int				left;
	int				right;
	pthread_t		thread;
	struct s_data	*link;
}				t_philo;

typedef struct s_data
{
	int				n_philo;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	int				must_eat;
	int				flag;
	unsigned long	start;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_data;

long int		ft_atoi(const char *str);
int				get_arg(t_data *info, int argc, char **argv);
void			init_fork_and_philo(t_data *p);
void			init_fork_and_philo_1(t_data *p);
void			create_thread(t_data *p);
void			ft_usleep(unsigned int time_to_wait);
unsigned long	get_time(void);
void			*live(void	*p);
void			take_f_e(t_philo *p);
void			check(t_data *p);
int				check_1(t_data *p, int all);
void			end(t_data *p);
void			print(t_philo *p, char *s);

#endif
