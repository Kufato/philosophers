/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:34:56 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/05 11:31:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philo[i].m_right_fork);
		pthread_mutex_destroy(&data->philo[i].m_start_eat);
		i++;
	}
	pthread_mutex_destroy(&data->m_death);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_nb_philo_max_meal);
}

void	end_routine(t_data *data)
{
	join_thread(data);
	destroy_mutex(data);
	free(data->philo);
	free(data);
}
