/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 14:04:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine(t_philo	*philo)
{
	usleep(500);
	pthread_mutex_lock(&philo->data->fork[philo->index]);
	if (any_death(philo, philo->index, -1) != 0)
		return (1);
	write_fork(philo);
	pthread_mutex_lock(&philo->data->fork[philo->index + 1]);
	if (any_death(philo, philo->index + 1, philo->index) != 0)
		return (1);
	write_fork(philo);
	last_meal(philo);
	write_eat(philo);
	sleep_x(philo->data->eat, philo);
	pthread_mutex_unlock(&philo->data->fork[philo->index + 1]);
	pthread_mutex_unlock(&philo->data->fork[philo->index]);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_sleep(philo);
	sleep_x(philo->data->sleep, philo);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_think(philo);
	return (0);
}

int	routine_pair(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->index + 1]);
	if (any_death(philo, philo->index + 1, -1) != 0)
		return (1);
	write_fork(philo);
	pthread_mutex_lock(&philo->data->fork[philo->index]);
	if (any_death(philo, philo->index, philo->index + 1) != 0)
		return (1);
	write_fork(philo);
	last_meal(philo);
	write_eat(philo);
	sleep_x(philo->data->eat, philo);
	pthread_mutex_unlock(&philo->data->fork[philo->index]);
	pthread_mutex_unlock(&philo->data->fork[philo->index + 1]);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_sleep(philo);
	sleep_x(philo->data->sleep, philo);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_think(philo);
	return (0);
}

void	write_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld	%d has taken a fork\n", get_time(philo->data), philo->index + 1);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld	%d is eating\n", get_time(philo->data), philo->index + 1);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld	%d is sleeping\n", get_time(philo->data), philo->index + 1);
	pthread_mutex_unlock(&philo->data->write);
}
