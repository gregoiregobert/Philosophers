/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:32:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/18 16:04:07 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	parsing_manager(t_data *data, int ac, char **av)
{
	if (checks_args(av) == -1)
		return (-1);
	if (parsing(data, ac, av) == -1)
	{
		free_all(data);
		return (-1);
	}
	if (check_value(data, ac) == -1)
		return (-1);
	return (0);
}

int	checks_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (str_isdigit(av[i]) == 0)
		{
			write(2, ERR_ARGTYPE, ft_strlen(ERR_ARGTYPE));
			return (-1);
		}
	}
	return (0);
}

int	parsing(t_data *data, int ac, char **av)
{
	if (ft_atoi(av[2], &data->die) == 1)
		return (-1);
	if (ft_atoi(av[3], &data->eat) == 1)
		return (-1);
	if (ft_atoi(av[4], &data->sleep) == 1)
		return (-1);
	data->meal_control = 0;
	data->death = -1;
	if (ac == 6)
	{
		if (ft_atoi(av[5], &data->many_meal) == 1)
			return (-1);
	}
	else
		data->many_meal = -1;
	return (0);
}

int	check_value(t_data *data, int ac)
{
	if (data->nb_philo < 1)
	{
		write(2, ERR_NBPHILO, ft_strlen(ERR_NBPHILO));
		return (-1);
	}
	if (data->die < 0 || data->eat < 0 || data->sleep < 0)
	{
		write(2, ERR_NEG, ft_strlen(ERR_NEG));
		return (-1);
	}
	if (ac == 6)
	{
		if (data->many_meal < 1)
		{
			write(2, ERR_NEG, ft_strlen(ERR_NEG));
			return (-1);
		}
	}
	return (0);
}
