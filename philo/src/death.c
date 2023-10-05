/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:11:32 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/05 11:21:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_data *data)
{
	int	tmp;

	pthread_mutex_lock(&data->m_death);
	tmp = data->death;
	pthread_mutex_unlock(&data->m_death);
	return (tmp);
}

void	set_death(t_philo *philo)
{
	long int	timestamp;

	pthread_mutex_lock(&philo->data->m_death);
	philo->data->death = 1;
	pthread_mutex_unlock(&philo->data->m_death);
	timestamp = diff_time(philo->data);
	pthread_mutex_lock(&philo->data->m_print);
	printf("%ld %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

int	death_checker(t_data *data)
{
	long int		time;
	unsigned int	i;

	while (!is_dead(data) && !check_max_meal(data))
	{
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock(&data->philo[i].m_start_eat);
			time = (get_time() - data->philo[i].start_eat);
			pthread_mutex_unlock(&data->philo[i].m_start_eat);
			if (time >= data->time_to_die)
			{
				set_death(&data->philo[i]);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
