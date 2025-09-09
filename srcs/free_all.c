/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:22:59 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 14:26:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->nb_philo)
		free(data->philo[i]);
	free(data->philo);
	free(data->fork);
	free(data);
}
