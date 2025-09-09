/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:17:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 14:32:08 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_manager(t_data *data)
{
	int	i;

	i = -1;
	if (init_philo(data) == -1)
		return ;
	if (init_death_control(data) == -1)
		return ;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philo[i]->th, NULL) != 0)
		{
			write(2, ERR_THJOIN, ft_strlen(ERR_THJOIN));
			return ;
		}
	}
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	if (gettimeofday(&data->start, 0) == -1)
		return (-1);
	while (++i < data->nb_philo)
	{
		data->philo[i]->index = i;
		data->philo[i]->many_meal = 0;
		if (pthread_create(&data->philo[i]->th, 0, &philosopher,
				(void *)data->philo[i]) != 0)
		{
			write(2, ERR_PTHR, ft_strlen(ERR_PTHR));
			return (-1);
		}
	}
	return (0);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->index == philo->data->nb_philo - 1)
		{
			if (are_you_last_pair(philo) == -1)
				return (0);
		}
		else
			if (are_you_pair(philo) == -1)
				return (0);
	}
	return (0);
}

int	are_you_pair(t_philo *philo)
{
	if (philo->index % 2 == 1)
	{
		if (routine(philo) != 0)
			return (-1);
	}
	else
		if (routine_pair(philo) != 0)
			return (-1);
	return (0);
}

int	are_you_last_pair(t_philo *philo)
{
	if (philo->index % 2 == 1)
	{
		if (routine_last_philo(philo) != 0)
			return (-1);
	}
	else
		if (routine_last_philo_pair(philo) != 0)
			return (-1);
	return (0);
}
