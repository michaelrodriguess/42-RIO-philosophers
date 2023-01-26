/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:08:42 by microdri          #+#    #+#             */
/*   Updated: 2023/01/26 16:28:45 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" 

int main(int argc, char **argv)
{
	t_philo *philos;
	t_rules rule;

	if (argc >= 5 && argc <= 6)
	{
		if(ft_init_rules(&rule, argc, argv) == 0)
			return (0);
		philos = ft_init_philos(&rule);
		if(ft_create_philos(philos) == 0)
		{
			free(rule.forks);
			free(rule.mutex_forks);
			free(philos);
			return (0);
		}
		ft_destroy_mutex(&rule);
		ft_free_trash(&philos);
	}
	return (0);
}
