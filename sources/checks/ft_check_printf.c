/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:57:54 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 17:50:56 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_printer(t_philo *philos, char *var)
{
	pthread_mutex_lock(&philos->rule->m_printf);
	printf("%ld\t%d\t%s\n", ft_time_formated(philos), philos->pid, var);
	pthread_mutex_unlock(&philos->rule->m_printf);
}

void	ft_check_printf(char c, t_philo *philos)
{
	if (c == 'f')
		ft_printer(philos, "Has taken a fork");
	else if (c == 'e')
		ft_printer(philos, "Is eating");
	else if (c == 's')
		ft_printer(philos, "Is sleeping");
	else if (c == 't')
		ft_printer(philos, "Is thinking");
	else if (c == 'd')
		ft_printer(philos, "died");
}
