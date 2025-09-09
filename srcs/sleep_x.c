/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:13:04 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 14:06:46 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleep_x(int time, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < time / 500)
	{
		usleep(500 * 1000);
		if (any_death(philo, -1, -1) != 0)
			return ;
	}
	usleep ((time % 500) * 1000);
}
