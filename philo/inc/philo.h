/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:11:21 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/05 11:22:31 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	########## START ##########

#ifndef PHILO_H
# define PHILO_H

//	########## INCLUDES ##########

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

//	########## STRCTURE ##########

typedef struct s_data
{
	int				death;
	int				max_meal;
	long int		start_time;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_philo_max_meal;
	struct s_philo	*philo;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_nb_philo_max_meal;
}				t_data;

typedef struct s_philo
{
	int				nb_meal;
	long int		start_eat;
	pthread_t		thread_id;
	unsigned int	id;
	struct s_data	*data;
	pthread_mutex_t	m_right_fork;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	m_start_eat;
}				t_philo;

//	########## FONCTIONS ##########

int			eat(t_philo *philo);
int			ft_strlen(char *str);
int			think(t_philo *philo);
int			is_dead(t_data *data);
int			snoring(t_philo *philo);
int			ft_atoi(const char *nptr);
int			init_thread(t_data *data);
int			join_thread(t_data *data);
int			take_fork(t_philo *philo);
int			main(int argc, char **argv);
int			death_checker(t_data *data);
int			check_max_meal(t_data *data);
int			check_format(int argc, char **argv);
int			the_usleep(t_data *data, unsigned int time);

void		end_routine(t_data *data);
void		set_death(t_philo *philo);
void		*start_routine(void *philo);
void		my_print(t_philo *philo, char *str);
void		init_philo_struct_mutex(t_data *data, t_philo *philo);

t_data		*init_data_struct(char **argv);

t_philo		*init_philo_struct(t_data *data);

long int	get_time(void);
long int	diff_time(t_data *data);

//	########## END ##########

#endif
