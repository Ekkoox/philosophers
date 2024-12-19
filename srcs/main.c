/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2024/12/19 19:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_philo *philo;
	(void)av;

	check_arguments(ac);
	check_format_arguments(av);
	philo = ft_calloc(sizeof(t_philo), ft_atoi(av[1]));
	if (!philo)
		return (EXIT_FAILURE);
	philo->philosophers = ft_atoi(av[1]);
	init_philo(philo, av);
	join_philo(philo);
	destroy_philo(philo);
	free(philo->forks);
	return (EXIT_SUCCESS);
}
