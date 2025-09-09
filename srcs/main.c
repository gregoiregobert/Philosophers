/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:31:28 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/18 16:02:28 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(av, ac);
	if (!data)
		return (0);
	if (parsing_manager(data, ac, av) == -1)
		return (0);
	philo_manager(data);
	free_all(data);
}
