/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:08:01 by mkardes           #+#    #+#             */
/*   Updated: 2022/04/07 15:22:58 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	get_binary(int pid, char *str)
{
	int	i;
	int	tmp;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **av)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(av[1]);
		get_binary(pid, av[2]);
	}
	return (0);
}
