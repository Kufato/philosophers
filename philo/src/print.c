/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:04:40 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/04 10:48:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_print(t_philo *philo, char *str)
{
	long int	timestamp;

	if (!is_dead(philo->data))
	{
		timestamp = diff_time(philo->data);
		pthread_mutex_lock(&philo->data->m_print);
		printf("%ld %d %s\n", timestamp, philo->id, str);
		pthread_mutex_unlock(&philo->data->m_print);
	}
}
