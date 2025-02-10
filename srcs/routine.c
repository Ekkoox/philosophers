/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:35 by enschnei          #+#    #+#             */
/*   Updated: 2025/02/10 20:02:48 by enschnei         ###   ########.fr       */
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
	// pthread_mutex_destroy(&print_mutex);
    return (EXIT_SUCCESS);
}

void only_one_philo(t_philo *philo)
{
	unsigned int start_time;

	start_time = get_time();
	if (philo->philosophers == 1)
	{
		printf("%u 1 is thinking\n", get_time() - philo->startTime);
		while (1)
        {
            printf("%u 1 has taken a fork\n", get_time() - philo->startTime);
			while (get_time() - start_time < philo->time_to_die)
            	usleep(100);
			if (get_time() - start_time >= philo->time_to_die)
            {
                printf("%u 1 died\n", get_time() - philo->startTime);
                exit(EXIT_FAILURE);
            }
			usleep(1000);
	    }
	}
}

int	init_philo(t_philo *philo, int ac, char **av)
{
    int i;

	i = 0;
	malloc_philo(philo);
	pthread_mutex_lock(philo->forks);
	philo[i].startTime = get_time();
	if (philo->philosophers == 1)
	{
	 	only_one_philo(philo);
	 	return (EXIT_SUCCESS);
	}
	while (i < philo->philosophers)
	{
		philo[i].startTime = get_time();
		philo[i].forks = philo[0].forks;
		philo[i].id = i + 1;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac > 5)
			philo[i].meals_required = ft_atoi(av[5]);
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

// De la part d'AK: Dans le cas ou le time to eat est superieur ou egal a time to sleep:
// il faut rajouter un time to think, pour eviter que le philo reprenne les fourchettes
// juste apres avoir finis de manger, le crevard.

// if (time to eat >= time to sleep)
// 		rajouter un time to think

// to do aussi:
// monitor la mort,
// mutex sur le print
// mutex sur le last meal
// chaque philo doit s'auto terminer dans le cas ou la simulation est finie (qqn est mort ou ils ont mange a leur faim)


void *philosopher_routine(void *param)
{
	t_philo *philo;
	
	philo = (t_philo *) param;
	pthread_mutex_lock(philo->forks);
	pthread_mutex_unlock(philo->forks);
	while (1)	
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		// locking_sequence()
		// pthreadm utex lock (end_simulation)
		// if (end)
		// { unlock(end_simulation)
			//return (1)}
		pthread_mutex_lock(philo->left_fork);
		printf("%u %d has taken a fork\n", get_time() - philo->startTime, philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%u %d has taken a fork\n", get_time() - philo->startTime, philo->id);
		printf("%u %d is eating\n", get_time() - philo->startTime, philo->id);
		//mutex pour lastmeal
		philo->lastEatTime = get_time();
		usleep(philo->time_to_eat * 1000);
		// update_meal_count();
        pthread_mutex_lock(&philo->meals_mutex);
        philo->meals_count++;
		printf("repas manger %d\n", philo->meals_count);
        pthread_mutex_unlock(&philo->meals_mutex);
		// unlocking sequence
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("%u %d is thinking\n", get_time() - philo->startTime, philo->id);
		printf("%u %d is sleeping\n", get_time() - philo->startTime, philo->id);
		usleep(philo->time_to_sleep * 1000);
	}	
}
