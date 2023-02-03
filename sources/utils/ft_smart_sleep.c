/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:54:34 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 20:15:49 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_smart_sleep(int time)
{
	long int	start;
	long int	current;

	start = ft_get_time();
	current = ft_get_time();
	while (current - start < time)
	{
		usleep(500);
		current = ft_get_time();
	}
}
