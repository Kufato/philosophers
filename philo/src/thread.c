/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:10:17 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/29 18:34:59 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_data *data)
{
	int				id_thread;
	unsigned int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philo)
	{
		id_thread = pthread_create(&data->philo[i].thread_id, NULL, \
					start_routine, &data->philo[i]);
		if (id_thread)
		{
			printf("philo: pthread_create: error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_thread(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread_id, NULL))
		{
			printf("philo: pthread_join: error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
