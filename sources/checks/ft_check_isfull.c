/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isfull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:46 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 17:29:56 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_isfull(t_philo *p)
{
	pthread_mutex_lock(&p->m_times_that_eat);
	if (p->times_that_eat < p->rule->number_each_philo_eat
		|| p->rule->number_each_philo_eat == -1)
	{
		pthread_mutex_unlock(&p->m_times_that_eat);
		return (1);
	}
	else
		pthread_mutex_unlock(&p->m_times_that_eat);
	return (0);
}
