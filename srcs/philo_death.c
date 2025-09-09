/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 14:25:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*death_control(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		usleep(1000);
		i = -1;
		while (++i < data->nb_philo)
			if (control_time(data, i) == 1)
				return (0);
	}
	return (0);
}

int	control_time(t_data *data, int i)
{
	pthread_mutex_lock(&data->dead);
	if (get_time(data) - data->philo[i]->last_meal
		> data->die && data->death == -1)
	{
		data->death = data->philo[i]->index + 1;
		pthread_mutex_unlock(&data->dead);
		write_dead(data);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	pthread_mutex_lock(&data->meal);
	if (data->meal_control == data->nb_philo)
	{
		pthread_mutex_unlock(&data->meal);
		pthread_mutex_lock(&data->dead);
		data->death = 0;
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->meal);
	return (0);
}

int	any_death(t_philo *philo, int index, int index2)
{
	pthread_mutex_lock(&philo->data->dead);
	if (philo->data->death > -1)
	{
		pthread_mutex_unlock(&philo->data->dead);
		if (index != -1)
			pthread_mutex_unlock(&philo->data->fork[index]);
		if (index2 != -1)
			pthread_mutex_unlock(&philo->data->fork[index2]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void	write_dead(t_data *data)
{
	pthread_mutex_lock(&data->write);
	printf("%ld	%d died\n", get_time(data), data->death);
	pthread_mutex_unlock(&data->write);
}

int	init_death_control(t_data *data)
{
	if (pthread_create(&data->th_control, 0, &death_control,
			(void *)data) != 0)
	{
		write(2, ERR_PTHR, ft_strlen(ERR_PTHR));
		return (-1);
	}
	if (pthread_detach(data->th_control) != 0)
	{
		write(2, ERR_THDET, ft_strlen(ERR_THDET));
		return (-1);
	}
	return (0);
}
