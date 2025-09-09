/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:02 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/18 16:03:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define ERR_ARGS "Wrong number of arguments\n4 minimum args (time in millisec) : number of philosophers, time before die, time to eat, time to sleep, minimum meals (optionnal)\nExemple : ./philo 5 50 5 5\n"
# define ERR_ARGTYPE "arguments must be numeric\n"
# define ERR_MALLOC "malloc failed\n"
# define ERR_NBPHILO "one philosophers minimum\n"
# define ERR_NEG "arguments must be positive value\n"
# define ERR_PTHR "failed to create thread\n"
# define ERR_THJOIN "failed to join thread\n"
# define ERR_MUTEX "failed to init mutex\n"
# define ERR_TIME "gettimeofday failed\n"
# define ERR_TIME "gettimeofday failed\n"
# define ERR_THDET "failed to detach thread\n"
# define ERR_INT "overflow by int arg\n"

typedef struct s_philo
{
	int				index;
	int				many_meal;
	long			last_meal;
	pthread_t		th;
	struct s_data	*data;	
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				many_meal;
	int				meal_control;
	int				death;
	pthread_t		th_control;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	t_philo			**philo;
	struct timeval	sec;
	struct timeval	start;
}	t_data;

void	free_all(t_data *data);
void	init_val(t_data *data, int i);
void	last_meal(t_philo *philo);
void	philo_manager(t_data *data);
void	sleep_x(int time, t_philo *philo);
void	write_dead(t_data *data);
void	write_eat(t_philo *philo);
void	write_fork(t_philo *philo);
void	write_sleep(t_philo *philo);
void	write_think(t_philo *philo);
void	*death_control(void *arg);
void	*philosopher(void *arg);
int		alloc_philo(t_data *data);
int		alloc_fork(t_data *data);
int		any_death(t_philo *philo, int index, int index2);
int		are_you_pair(t_philo *philo);
int		are_you_last_pair(t_philo *philo);
int		check_value(t_data *data, int ac);	
int		checks_args(char **av);
int		control_time(t_data *data, int i);
int		ft_atoi(const char *str, int *ret);
int		ft_isdigit(int c);
int		init_death_control(t_data *data);
int		init_philo(t_data *data);
int		init_nbphilo(t_data *data, char **av, int ac);
int		one_philo(t_philo *philo);
int		parsing(t_data *data, int ac, char **av);
int		parsing_manager(t_data *data, int ac, char **av);
int		routine(t_philo	*philo);
int		routine_pair(t_philo *philo);
int		routine_last_philo(t_philo	*philo);
int		routine_last_philo_pair(t_philo	*philo);
int		str_isdigit(char *str);
long	get_time(t_data *data);
size_t	ft_strlen(const char *str);
t_data	*init_data(char **av, int ac);

#endif