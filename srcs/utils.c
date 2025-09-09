/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:50:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/17 13:04:34 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (*str++)
		l++;
	return (l);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	str_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
			return (0);
	return (1);
}

int	ft_atoi(const char *str, int *ret)
{
	int	pos;

	pos = 1;
	*ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			pos *= -1;
	while (*str >= '0' && *str <= '9')
	{
		*ret = *ret * 10 + (*str++ - '0');
		if (*ret > INT_MAX || *ret < 0)
		{
			write(2, ERR_INT, ft_strlen(ERR_INT));
			return (1);
		}
	}
	*ret *= pos;
	return (0);
}

long	get_time(t_data *data)
{
	if (gettimeofday(&data->sec, 0) == -1)
	{
		write(2, ERR_TIME, ft_strlen(ERR_TIME));
		return (-1);
	}
	return ((data->sec.tv_sec * 1000 + data->sec.tv_usec / 1000)
		- (data->start.tv_sec * 1000 + data->start.tv_usec / 1000));
}
