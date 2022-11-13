/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:51:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/20 16:44:56 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	value;
	int		sig;

	value = 0;
	i = 0;
	sig = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		value *= 10;
		value += nptr[i] - 48;
		i++;
	}
	return ((int)value * sig);
}
