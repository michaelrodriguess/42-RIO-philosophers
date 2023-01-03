/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:44:48 by microdri          #+#    #+#             */
/*   Updated: 2023/01/02 21:48:27 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_create_philo(t_philo *philos)
{
	int i;

	i = 0;
	philos->philo = malloc(philos->rules->number_of_philosophers * sizeof(pthread_t));
	while (i < philos->rules->number_of_philosophers)
	{
		if(pthread_create(&philos->philo[i], 0, &ft_routine, NULL) != 0)
			perror("Failed to create Thread");	
		i++;
	}

	i = 0;
	while (i < philos->rules->number_of_philosophers)
	{
		if(pthread_join(philos->philo[i], NULL) != 0)
			perror("Failed to join Thread");
		i++;
	}
	return (0);
}

