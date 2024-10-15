/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/15 19:21:42 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_philo *philo;
	(void)av;

	check_arguments(ac);
	check_format_arguments(ac, av);
	philo->philosophers = ft_atoi(av[1]);
	pthread_mutex_t forks[philo->philosophers];
	init_argument(philo, av);
	init_philo(philo, av);
	philosopher_routine(philo);
	destroy_philo(philo);
	return (EXIT_SUCCESS);
}
