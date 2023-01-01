/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:44:48 by microdri          #+#    #+#             */
/*   Updated: 2023/01/01 12:55:41 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_create_philo(t_data *var)
{
	int i;

	i = 0;
	var->philo = malloc(var->number_of_philosophers * sizeof(pthread_t));
	while (i < var->number_of_philosophers)
	{
		if(pthread_create(&var->philo[i], 0, &ft_routine, NULL) != 0)
			perror("Failed to create Thread");
		
		i++;
	}

	i = 0;
	while (i < var->number_of_philosophers)
	{
		if(pthread_join(var->philo[i], NULL) != 0)
			perror("Failed to join Thread");
		i++;
	}
	return (0);
}

