/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:00:22 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/04 09:36:49 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->m_left_fork);
	pthread_mutex_unlock(&philo->m_right_fork);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	my_print(philo, "has taken a fork");
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(philo->m_left_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->m_right_fork);
	my_print(philo, "has taken a fork");
	if (is_dead(philo->data))
	{
		drop_fork(philo);
		return (1);
	}
	return (0);
}

int	snoring(t_philo *philo)
{
	my_print(philo, "is sleeping");
	if (the_usleep(philo->data, philo->data->time_to_sleep))
		return (1);
	return (0);
}

int	think(t_philo *philo)
{
	my_print(philo, "is thinking");
	if (is_dead(philo->data))
		return (1);
	return (0);
}

int	eat(t_philo *philo)
{
	my_print(philo, "is eating");
	pthread_mutex_lock(&philo->m_start_eat);
	philo->start_eat = get_time();
	pthread_mutex_unlock(&philo->m_start_eat);
	if (the_usleep(philo->data, philo->data->time_to_eat))
	{
		drop_fork(philo);
		return (1);
	}
	drop_fork(philo);
	if (philo->data->max_meal != -1)
	{
		philo->nb_meal += 1;
		if (philo->nb_meal == philo->data->max_meal)
		{
			pthread_mutex_lock(&philo->data->m_nb_philo_max_meal);
			philo->data->nb_philo_max_meal += 1;
			pthread_mutex_unlock(&philo->data->m_nb_philo_max_meal);
		}
	}
	return (0);
}
