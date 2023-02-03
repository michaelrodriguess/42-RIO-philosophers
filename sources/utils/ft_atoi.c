/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:31:12 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 18:39:07 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_isspace(int c)
{
	if ((c == '\f') || (c == '\n') || (c == '\r') || (c == '\t')
		|| (c == '\v') || (c == ' '))
		return (1);
	return (0);
}

long	ft_atoi(const char *n)
{
	long	i;
	int		signal;
	long	result_value;

	result_value = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(n[i]))
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			signal = -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{	
		result_value = result_value * 10 + n[i] - '0';
		i++;
	}
	return (result_value * signal);
}
