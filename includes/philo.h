/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:13:16 by microdri          #+#    #+#             */
/*   Updated: 2023/01/02 21:37:11 by microdri         ###   ########.fr       */
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
	pthread_mutex *mutex_forks;
}	t_rules;

typedef struct s_philo
{
	int	fork;
	pthread_t *philo;
	t_rules *rules;
}		t_philo;

void	ft_check_init_value(t_data *var, int argc, char **argv);
void	*ft_routine(void *);
int		ft_check_isdigit(int argc, char **argv);
int		ft_create_philo(t_data *var);
long	ft_atoi(const char *n);

#endif
