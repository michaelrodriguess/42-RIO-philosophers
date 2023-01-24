/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:12:15 by microdri          #+#    #+#             */
/*   Updated: 2023/01/24 14:12:40 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_init_rules(t_rules *rule, int argc, char **argv)
{

	if (argc >= 5 && argc <= 6)
	{
		if(ft_check_isdigit(argc, argv) == 0)
			return (0);
		rule->number_of_philosophers = ft_atoi(argv[1]);
		rule->time_to_die = ft_atoi(argv[2]);
		rule->time_to_eat = ft_atoi(argv[3]);
		rule->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			rule->number_each_philo_eat = ft_atoi(argv[5]);
		rule->forks = malloc(rule->number_of_philosophers * sizeof(int));
		if(!rule->forks)
		{
			return(0);
		}
		rule->mutex_forks = malloc(rule->number_of_philosophers * sizeof(pthread_mutex_t));
		if(!rule->mutex_forks)
		{
			write(1, "error", 6);
			write(1, "\n", 1);
			return (0);
		}
		return(1);
	}
	else
		return (0);
}
