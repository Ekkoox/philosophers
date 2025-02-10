/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:49:05 by enschnei          #+#    #+#             */
/*   Updated: 2025/02/10 18:51:44 by enschnei         ###   ########.fr       */
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

// void	check_death(t_philo *philo) 
// {
//     int i;

//     i = 0;    
// 	while (1) 
//     {
// 		while (i < philo->philosophers) 
//         {
// 			if (philo[i].lastEatTime != (unsigned int)-1 && get_time() - philo[i].lastEatTime >= philo[i].time_to_die) 
//             {
// 				printf("%d dead at %u\n", philo[i].id, get_time() - philo[i].lastEatTime);
// 				return;
// 			}
//             i++;
// 		}
// 		usleep(1000);
// 	}
// }

void check_death(t_philo *philo) 
{
    int i;
    int finished_eating;

    while (1) 
    {
        i = 0;
        finished_eating = 0;
        // printf("meals required %d\n", philo->meals_required);
        while (i < philo->philosophers) 
        {
            pthread_mutex_lock(&philo[i].meals_mutex);
            if (philo->meals_required > 0 && philo[i].meals_count >= philo->meals_required)
                finished_eating++;
            pthread_mutex_unlock(&philo[i].meals_mutex);
            // if (philo[i].lastEatTime != (unsigned int)-1 
            //     && get_time() - philo[i].lastEatTime >= philo[i].time_to_die) 
            // {
            //     printf("%d %u died\n", philo[i].id, get_time() - philo[i].lastEatTime);
            //     return;
            // }
            if (finished_eating == philo->philosophers)
            {
                usleep(5000);
                pthread_mutex_lock(&philo[i].meals_mutex);
                printf("All philosophers have eaten enough times. Stopping simulation.\n");
                pthread_mutex_unlock(&philo[i].meals_mutex);
                exit(0);
            }
            i++;
        }
        // printf("finished_eating = %d\n", finished_eating);
        usleep(1000);
    }
}
