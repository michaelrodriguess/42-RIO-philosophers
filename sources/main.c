/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:08:42 by microdri          #+#    #+#             */
/*   Updated: 2022/12/31 20:59:18 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" 

int main(int argc, char **argv)
{
	t_data var;

	ft_check_init_value(&var, argc, argv);
	
	printf("%d\n%d\n%d\n%d\n%d\n", var.number_of_philosophers, var.time_to_die, var.time_to_eat, var.time_to_sleep, var.number_each_philo_eat);
}
