/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/12/19 20:25:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int malloc_philo(t_philo *philo)
{
	int i;

    i = 0;
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philosophers);
    if (!philo->forks)
	{
        perror("Failed to allocate memory for forks");
        exit(EXIT_FAILURE);
    }
	while (i < philo->philosophers)
	{
		philo[i].lastEatTime = -1;
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
		philo[i].startTime = get_time();
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
	check_death(philo);
    return (EXIT_SUCCESS);
}

void only_one_philo(t_philo *philo)
{
	unsigned int start_time;

	start_time = get_time();
	if (philo->philosophers == 1)
	{
		printf("%u %d is thinking\n", get_time() - philo->startTime, philo->id);
		while (1)
        {
            printf("%u %d has taken a fork\n", get_time() - philo->startTime, philo->id);
			while (get_time() - start_time < philo->time_to_die)
            	usleep(100);
			if (get_time() - start_time >= philo->time_to_die)
            {
                printf("%u %d MORT À %u\n", get_time() - philo->startTime, philo->id, get_time() - start_time);
                exit(EXIT_FAILURE);
            }
			usleep(1000);
	    }
	}
}

void *philosopher_routine(void *param)
{
	t_philo *philo;
	
	philo = (t_philo *) param;
	pthread_mutex_lock(philo->forks);
	pthread_mutex_unlock(philo->forks);
	if (philo->philosophers == 1)
    {
        only_one_philo(philo);
        return NULL; // Terminer la routine pour le philosophe unique
    }
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(philo->left_fork);
		printf("%u %d has taken a fork\n", get_time() - philo->startTime, philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%u %d has taken a fork\n", get_time() - philo->startTime, philo->id);
		printf("%u %d is eating\n", get_time() - philo->startTime, philo->id);
		philo->lastEatTime = get_time();
		usleep(philo->time_to_eat * 1000);
        pthread_mutex_lock(&philo->meals_mutex);
        philo->meals_count++;
        pthread_mutex_unlock(&philo->meals_mutex);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("%u %d is thinking\n", get_time() - philo->startTime, philo->id);
		printf("%u %d is sleeping\n", get_time() - philo->startTime, philo->id);
		usleep(philo->time_to_sleep * 1000);
	}	
}
