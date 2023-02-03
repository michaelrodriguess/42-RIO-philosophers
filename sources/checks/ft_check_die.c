/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:50 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 17:26:19 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_die(t_philo *philos)
{
	pthread_mutex_lock(&philos->rule->m_flag_someone_die);
	if (philos->rule->flag_someone_die == 1)
	{
		pthread_mutex_unlock(&philos->rule->m_flag_someone_die);
		return (1);
	}
	else
		pthread_mutex_unlock(&philos->rule->m_flag_someone_die);
	return (0);
}
