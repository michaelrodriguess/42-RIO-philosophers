/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:11:21 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 16:58:57 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long int ft_time_formated(t_philo *philos)
{
	long int current_time;

	current_time = ft_get_time() - philos->rule->time_update;
	
	return(current_time);
}

long int ft_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, 0);

	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}
