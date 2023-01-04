/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:44:48 by microdri          #+#    #+#             */
/*   Updated: 2023/01/03 22:17:26 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_create_philos(t_philo *philos)
{
	int i;
	
	i = 0;
	while (i < philos->rule->number_of_philosophers)
	{
		if(pthread_create(philos[i].philo, 0, &ft_routine, NULL) != 0)
		{
			write(2, "Error\n", 6);
			return (0);	
		}
		i++;
	}
	i = 0;
	while (i < philos->rule->number_of_philosophers)
	{
		if(pthread_join(philos->philo[i], NULL) != 0)
		{
			write(2, "Error\n", 6);
			return (0);	
		}
		i++;
		
		i++;
	}
	return (0);
}


