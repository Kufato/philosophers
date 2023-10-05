/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:04:28 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/13 10:44:23 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_struct_mutex(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&philo[i].m_right_fork, NULL);
		pthread_mutex_init(&philo[i].m_start_eat, NULL);
		i++;
	}
	i = 0;
	while (i < (data->nb_philo - 1))
	{
		philo[i].m_left_fork = &philo[i + 1].m_right_fork;
		i++;
	}
	philo[i].m_left_fork = &philo[0].m_right_fork;
}

t_philo	*init_philo_struct(t_data *data)
{
	t_philo			*philo;
	unsigned int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
	{
		free(data);
		return (NULL);
	}
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_meal = 0;
		philo[i].data = data;
		philo[i].start_eat = get_time();
		i++;
	}
	return (philo);
}

t_data	*init_data_struct(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->death = 0;
	data->nb_philo_max_meal = 0;
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_meal = ft_atoi(argv[5]);
	else
		data->max_meal = -1;
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_death, NULL);
	pthread_mutex_init(&data->m_nb_philo_max_meal, NULL);
	return (data);
}
