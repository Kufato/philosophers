/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:19:13 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/30 14:10:56 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine_one_philo(t_philo *philo)
{
	my_print(philo, "has taken a fork");
	the_usleep(philo->data, philo->data->time_to_die);
	my_print(philo, "died");
}

static int	routine(t_philo *philo)
{
	if (take_fork(philo))
		return (1);
	if (eat(philo))
		return (1);
	if (snoring(philo))
		return (1);
	if (think(philo))
		return (1);
	return (0);
}

void	*start_routine(void *philo)
{
	t_philo	*tmp_philo;

	tmp_philo = philo;
	if (tmp_philo->data->nb_philo == 1)
	{
		routine_one_philo(tmp_philo);
		return (NULL);
	}
	if (tmp_philo->id % 2 == 0)
		usleep(500);
	while (!check_max_meal(tmp_philo->data) && !is_dead(tmp_philo->data))
	{
		if (routine(tmp_philo))
			break ;
	}
	return (NULL);
}
