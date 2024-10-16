/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/16 19:17:37 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int join_philo(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int malloc_philo(t_philo *philo)
{
	int i;

    i = 0;
	printf("%d\n", philo->philosophers);
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philosophers);
    if (!philo->forks)
	{
        perror("Failed to allocate memory for forks");
        exit(EXIT_FAILURE);
    }
	while (i < philo->philosophers)
	{
		pthread_mutex_init(philo->forks + i, NULL);
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
        pthread_mutex_destroy(philo->forks + i);
       i++; 
    }
    return (EXIT_SUCCESS);
}
int	init_philo(t_philo *philo, char **av)
{
    int i;

	i = 0;
	malloc_philo(philo);
	pthread_mutex_lock(philo->forks);
	while (i < philo->philosophers)
	{
		philo[i].forks = philo[0].forks;
		philo[i].id = i + 1;
		philo[i].time_to_eat = ft_atoi(av[2]);
		philo[i].time_to_sleep = ft_atoi(av[3]);
		philo[i].time_to_die = ft_atoi(av[4]);
		philo[i].left_fork = &philo->forks[i];
		philo[i].right_fork = &philo->forks[(i + 1) % philo->philosophers];
		if (pthread_create(&philo[i].thread, NULL, philosopher_routine, &philo[i]) != 0)
		{
			perror("Failed to create thread");
			return (EXIT_FAILURE);
		}
		i++;
	}
	pthread_mutex_unlock(philo->forks);
    return (EXIT_SUCCESS);
}

void *philosopher_routine(void *param)
{
	t_philo *philo;
	
	philo = (t_philo *) param;
	pthread_mutex_lock(philo->forks);
	pthread_mutex_unlock(philo->forks);
	while (1)
	{
		printf("Philosopher %d is thinking\n", philo->id);
		usleep(1000);
		pthread_mutex_lock(philo->left_fork);
		printf("Philosopher %d has taken left fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("Philosopher %d has taken right fork\n", philo->id);
		printf("Philosopher %d is eating\n", philo->id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("Philosopher %d is sleeping\n", philo->id);
		usleep(philo->time_to_sleep * 1000);
	}
}
