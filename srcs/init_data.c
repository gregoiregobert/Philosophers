/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:11:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/18 16:02:23 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(char **av, int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (0);
	}
	if (init_nbphilo(data, av, ac) == -1)
		return (0);
	if (alloc_fork(data) == -1)
		return (0);
	if (alloc_philo(data) == -1)
		return (0);
	pthread_mutex_init(&data->dead, 0);
	pthread_mutex_init(&data->write, 0);
	pthread_mutex_init(&data->meal, 0);
	return (data);
}

int	alloc_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo *) * (data->nb_philo + 1));
	if (!data->philo)
	{
		while (++i < data->nb_philo + 1)
			free(data->fork++);
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
	while (++i < data->nb_philo + 1)
	{
		data->philo[i] = malloc(sizeof(t_philo));
		if (!data->philo[i])
		{
			while (*data->philo)
				free(*data->philo++);
			free(data->philo);
			free(data);
			return (-1);
		}
		init_val(data, i);
	}
	return (0);
}

void	init_val(t_data *data, int i)
{
	data->philo[i]->data = data;
	data->philo[i]->last_meal = 0;
}

int	alloc_fork(t_data *data)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
	{
		free(data);
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], 0) != 0)
		{
			free(data->fork);
			free(data);
			write(2, ERR_MUTEX, ft_strlen(ERR_MUTEX));
			return (-1);
		}		
	}
	return (0);
}

int	init_nbphilo(t_data *data, char **av, int ac)
{
	if (ac < 5 || ac > 6)
	{
		write(2, ERR_ARGS, ft_strlen(ERR_ARGS));
		return (-1);
	}
	if (ft_atoi(av[1], &data->nb_philo) == 1)
	{
		free(data);
		return (-1);
	}
	if (data->nb_philo < 1)
	{
		free(data);
		write(2, ERR_NBPHILO, ft_strlen(ERR_NBPHILO));
		return (-1);
	}
	return (0);
}
