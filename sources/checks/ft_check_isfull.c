/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isfull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:46 by microdri          #+#    #+#             */
/*   Updated: 2023/01/27 18:52:23 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_check_isfull(t_philo *p)
{

	if(p->times_that_eat < p->rule->number_each_philo_eat || p->rule->number_each_philo_eat == -1)
		return (1);
	return (0);
}
