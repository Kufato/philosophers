/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:37:27 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/30 15:33:20 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_arg_are_numerics(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] && !str_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_arg_value(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] && ((ft_atoi(argv[i]) == -1 && ft_strlen(argv[i]) > 2)
				|| ft_atoi(argv[i]) < 1))
			return (0);
		i++;
	}
	return (1);
}

int	check_format(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		printf("Wrong number of arguments\n");
	else if (!check_arg_are_numerics(argv))
		printf("Non-numerical argument\n");
	else if (!check_arg_value(argv))
		printf("Wrong format\n");
	else
		return (1);
	return (0);
}
