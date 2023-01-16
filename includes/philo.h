/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:13:16 by microdri          #+#    #+#             */
/*   Updated: 2023/01/16 19:37:57 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_rules
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_each_philo_eat;
	int *forks;
	pthread_mutex_t *mutex_forks;
}	t_rules;

typedef struct s_philo
{
	int pid;
	int	fork_first;
	int fork_second;
	pthread_t philo;
	t_rules *rule;
}		t_philo;

void	ft_init_forks(t_philo *philos, int index_philo);
void	*ft_routine(void *philo);
void	ft_take_fork(t_philo *philos, int which_fork);
int		ft_create_philos(t_philo *philos);
int		ft_init_rules(t_rules *rule, int argc, char **argv);
int		ft_check_isdigit(int argc, char **argv);
long	ft_atoi(const char *n);
t_philo	*ft_init_philos(t_rules *rule);

#endif
