/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:26:21 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/05 11:25:37 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (!check_format(argc, argv))
		return (1);
	data = init_data_struct(argv);
	if (!data)
		return (1);
	philo = init_philo_struct(data);
	if (!philo)
		return (1);
	init_philo_struct_mutex(data, philo);
	data->philo = philo;
	if (init_thread(data))
	{
		end_routine(data);
		return (1);
	}
	if (data->nb_philo > 1)
		death_checker(data);
	end_routine(data);
	return (0);
}
