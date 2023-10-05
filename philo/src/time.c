/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:09:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/30 11:11:11 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	long int		start_time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (-1);
	start_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (start_time);
}

long int	diff_time(t_data *data)
{
	long int		time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time - data->start_time);
}

int	the_usleep(t_data *data, unsigned int time)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) <= time)
	{
		if (is_dead(data))
			return (1);
		usleep(100);
	}
	return (0);
}
