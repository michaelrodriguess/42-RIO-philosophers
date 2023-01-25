/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:08:42 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 14:11:51 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" 

int main(int argc, char **argv)
{
	t_philo *philos;
	t_rules rule;

	if(ft_init_rules(&rule, argc, argv) == 0)
		return (0);
	philos = ft_init_philos(&rule);
	if(ft_create_philos(philos) == 0)
		return (0);
	ft_destroy_mutex(&rule);
}
