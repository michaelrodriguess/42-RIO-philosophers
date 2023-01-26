/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:12:15 by microdri          #+#    #+#             */
/*   Updated: 2023/01/26 16:34:14 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_init_rules(t_rules *rule, int argc, char **argv)
{
	if(ft_check_isdigit(argc, argv) == 0)
		return (0);
	rule->number_of_philosophers = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	rule->flag_someone_die = 1;
	if (argc == 6)
		rule->number_each_philo_eat = ft_atoi(argv[5]);
	rule->forks = malloc(rule->number_of_philosophers * sizeof(int));
	if(!rule->forks)
	{
		free(rule->forks);
		return(0);
	}
	rule->mutex_forks = malloc(rule->number_of_philosophers * sizeof(pthread_mutex_t));
	if(!rule->mutex_forks)
	{
		free(rule->mutex_forks);
		return (0);
	}
	ft_init_mutex(rule);
	return(1);
}
