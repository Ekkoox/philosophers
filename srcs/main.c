/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/22 19:25:31 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_philo *philo) {
	while (1) {
		for (int i = 0; i < philo->philosophers; i++) {
			if (philo[i].lastEatTime != (unsigned int)-1 && get_time() - philo[i].lastEatTime >= philo[i].time_to_die) {
				printf("%d MORT A %u\n", philo[i].id, get_time() - philo[i].lastEatTime);
				return;
			}
		}
	}
}

int main(int ac, char **av)
{
	t_philo *philo;
	(void)av;

	check_arguments(ac);
	check_format_arguments(ac, av);
	philo = ft_calloc(sizeof(t_philo), ft_atoi(av[1]));
	if (!philo)
		return (EXIT_FAILURE);
	philo->philosophers = ft_atoi(av[1]);
	init_philo(philo, av);
	check_death(philo);
	join_philo(philo);
	destroy_philo(philo);
	free(philo->forks);
	return (EXIT_SUCCESS);
}
