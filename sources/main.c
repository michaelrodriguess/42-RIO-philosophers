/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:08:42 by microdri          #+#    #+#             */
/*   Updated: 2023/01/02 21:46:27 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" 

int main(int argc, char **argv)
{
	t_philo philos;

	ft_check_init_value(&philos, argc, argv);
	ft_create_philo(&philos);
}
