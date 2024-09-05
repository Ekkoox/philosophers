/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:49:05 by enschnei          #+#    #+#             */
/*   Updated: 2024/09/05 19:41:29 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_format(int ac, char **av)
{
	int	flag;

	(void)ac;
	flag = 0;
	if (ft_atoi(av[1]) < 1)
	{
		flag += 1;
		ft_putstr_fd("The number of philosopher must be positive\n", 2);
	}
	if (ft_atoi(av[2]) < 60)
	{
		flag += 1;
		ft_putstr_fd("The time to die must be greater or equal to 60ms\n", 2);
	}
	if (ft_atoi(av[3]) < 60)
	{
		flag += 1;
		ft_putstr_fd("The time to eat must be greater or equal to 60ms\n", 2);
	}
	if (ft_atoi(av[4]) < 60)
	{
		flag += 1;
		ft_putstr_fd("The time to sleep must be greater or equal to 60ms\n", 2);
	}
	if (ft_atoi(av[5]) < 1)
	{
		flag += 1;
		ft_putstr_fd("The number of times the philosopher eat must be positive\n", 2);
	}
	if (flag > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
