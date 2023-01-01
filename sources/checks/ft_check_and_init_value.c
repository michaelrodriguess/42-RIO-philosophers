/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_init_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:22:20 by microdri          #+#    #+#             */
/*   Updated: 2022/12/31 20:51:03 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_check_init_value(t_data *var, int argc, char **argv)
{	
	if (argc >= 5 && argc <= 6)
	{
		if(ft_check_isdigit(argc, argv) == 0)
			exit(0);
		var->number_of_philosophers = ft_atoi(argv[1]);
		var->time_to_die = ft_atoi(argv[2]);
		var->time_to_eat = ft_atoi(argv[3]);
		var->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			var->number_each_philo_eat = ft_atoi(argv[5]);
	}
}

