/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:23:53 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/26 11:04:18 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi_end(const char *nptr, int i, int n, long int p)
{
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (p * n > 2147483647)
			return (-1);
		if (p * n < -2147483648)
			return (0);
		p = p * 10 + (nptr[i] - 48);
		i++;
	}
	return (p);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			n;
	long int	p;

	i = 0;
	p = 0;
	n = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = n * -1;
		i++;
	}
	p = ft_atoi_end(nptr, i, n, p);
	p = p * n;
	return (p);
}
