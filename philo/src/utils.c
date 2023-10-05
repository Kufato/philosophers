/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:44:19 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/29 19:00:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_max_meal(t_data *data)
{
	pthread_mutex_lock(&data->m_nb_philo_max_meal);
	if (data->nb_philo_max_meal == data->nb_philo)
	{
		pthread_mutex_unlock(&data->m_nb_philo_max_meal);
		return (1);
	}
	pthread_mutex_unlock(&data->m_nb_philo_max_meal);
	return (0);
}
