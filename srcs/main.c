/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2025/02/10 19:34:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_philo *philo;

	check_arguments(ac);
	check_format_arguments(av);
	philo = ft_calloc(sizeof(t_philo), ft_atoi(av[1]));
	if (!philo)
		return (EXIT_FAILURE);
	philo->philosophers = ft_atoi(av[1]);
	init_philo(philo, ac, av);
	join_philo(philo);
	destroy_philo(philo);
	free(philo->forks);
	return (EXIT_SUCCESS);
}
