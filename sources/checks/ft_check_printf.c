/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:57:54 by microdri          #+#    #+#             */
/*   Updated: 2023/02/02 22:21:40 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_check_printf(char c, t_philo *philos)
{
	if (c == 'f')
	{
		pthread_mutex_lock(&philos->rule->m_printf);
		printf("%ld\t%d\t%s\n", ft_time_formated(philos), philos->pid, "Has taken a fork");
		pthread_mutex_unlock(&philos->rule->m_printf);

	} else if (c == 'e')
	{
		pthread_mutex_lock(&philos->rule->m_printf);
		printf("%ld\t%d\tIs eating\n", ft_time_formated(philos), philos->pid);
		pthread_mutex_unlock(&philos->rule->m_printf);

	} else if (c == 's')
	{
		pthread_mutex_lock(&philos->rule->m_printf);
		printf("%ld\t%d\tIs sleeping\n", ft_time_formated(philos), philos->pid);
		pthread_mutex_unlock(&philos->rule->m_printf);
	}
	else if (c == 'd')
	{
		pthread_mutex_lock(&philos->rule->m_printf);
		printf("%ld\t%d\tdied\n", ft_time_formated(philos), philos->pid);
		pthread_mutex_unlock(&philos->rule->m_printf);	
	}
}

