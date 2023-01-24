/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:11:42 by microdri          #+#    #+#             */
/*   Updated: 2023/01/24 14:12:07 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_init_mutex(t_rules *rule)
{
	int i;

	i = 0;
	while(i < rule->number_of_philosophers)
	{
		pthread_mutex_init(&rule->mutex_forks[i], NULL);
		i++;
	}
}
