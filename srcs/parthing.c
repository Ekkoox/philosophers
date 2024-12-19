/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:49:05 by enschnei          #+#    #+#             */
/*   Updated: 2024/12/19 19:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_arguments(int ac)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error number of arguments\n", 2);
		exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_format_arguments(char **av)
{
	int	flag;

	flag = 0;
	if (ft_atoi(av[1]) < 1)
	{
		flag += 1;
		ft_putstr_fd("The number of philosopher must be positive\n", 2);
	}
	if (flag > 0)
		exit (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_death(t_philo *philo) 
{
    int i;

    i = 0;    
	while (1) 
    {
		while (i < philo->philosophers) 
        {
			if (philo[i].lastEatTime != (unsigned int)-1 && get_time() - philo[i].lastEatTime >= philo[i].time_to_die) 
            {
				printf("%d MORT A %u\n", philo[i].id, get_time() - philo[i].lastEatTime);
				return;
			}
            i++;
		}
		usleep(1000);
	}
}

