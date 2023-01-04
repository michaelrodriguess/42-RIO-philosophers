/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:41:45 by microdri          #+#    #+#             */
/*   Updated: 2023/01/03 22:10:03 by microdri         ###   ########.fr       */
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
		return(1);
	}
	else
		return (0);
}

