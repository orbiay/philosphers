/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:06:01 by orbiay            #+#    #+#             */
/*   Updated: 2022/03/30 12:01:57 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	rest;
	int	sen;

	i = 0;
	rest = 0;
	sen = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sen = sen * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		rest = rest * 10 + str[i] - 48;
		i++;
	}
	return (rest * sen);
}
