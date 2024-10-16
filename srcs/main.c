/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/16 19:19:32 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	join_philo(philo);
	destroy_philo(philo);
	return (EXIT_SUCCESS);
}
