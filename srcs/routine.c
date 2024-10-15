/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/15 19:21:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_philo *philo, char **av)
{
    int i;

    i = 0;
	while (i < philo->philosophers)
	{
		pthread_mutex_init(philo->forks, NULL);
		i++;
	}
	i = 0;
	while (i < philo->philosophers)
	{
		philo[i].id =   i + 1;
		philo[i].time_to_eat = ft_atoi(av[2]);
		philo[i].time_to_sleep = ft_atoi(av[3]);
		philo[i].time_to_die = ft_atoi(av[4]); 
		philo[i].left_fork = philo->forks;
		// philo[i].right_fork = philo->forks[(i + 1) % number_of_philosophers];
		if (pthread_create(philo->philosophers, NULL, philosopher_routine, &philo[i]) != 0)
		{
			perror("Failed to create thread");
			return (EXIT_FAILURE);
		}
		i++;
	}
    return (EXIT_SUCCESS);
}

int destroy_philo(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->philosophers)
    {
        pthread_mutex_destroy(philo->philosophers);
       i++; 
    }
    return (EXIT_SUCCESS);
}

int	*philosopher_routine(t_philo *philo)
{
	while (1)
	{
		// Penser
		printf("Philosopher %d is thinking\n", philo->id);
		usleep(1000); // Simulation du temps de réflexion
		// Prendre les fourchettes (mutex lock)
		pthread_mutex_lock(philo->left_fork);
		printf("Philosopher %d has taken left fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("Philosopher %d has taken right fork\n", philo->id);
		// Manger
		printf("Philosopher %d is eating\n", philo->id);
		usleep(philo->time_to_eat * 1000); // Simulation du temps pour manger
		// Reposer les fourchettes (mutex unlock)
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		// Dormir
		printf("Philosopher %d is sleeping\n", philo->id);
		usleep(philo->time_to_sleep * 1000); // Simulation du temps pour dormir
	}
	return (EXIT_SUCCESS);
}
