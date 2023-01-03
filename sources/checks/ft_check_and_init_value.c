/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_init_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:22:20 by microdri          #+#    #+#             */
/*   Updated: 2023/01/02 21:47:05 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_check_init_value(t_rules *rule, int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
	{
		if(ft_check_isdigit(argc, argv) == 0)
			exit(0);
		rule->number_of_philosophers = ft_atoi(argv[1]);
		rule->time_to_die = ft_atoi(argv[2]);
		rule->time_to_eat = ft_atoi(argv[3]);
		rule->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			rule->number_each_philo_eat = ft_atoi(argv[5]);
	}
}

