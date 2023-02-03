/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_trash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:07:47 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 18:39:41 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_free_trash(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*philos)->rule->number_of_philosophers)
	{
		free((*philos)->rule->forks);
		free((*philos)->rule->mutex_forks);
		free(philos);
		i++;
	}
}
