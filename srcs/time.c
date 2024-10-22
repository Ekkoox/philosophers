/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:51:37 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/22 17:39:02 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int get_time()
{
    struct timeval time;
    
    // pthread_mutex_lock(philo->time);
    if(gettimeofday(&time, NULL) == -1)
    {
        perror("Error time receive");
        exit(EXIT_FAILURE);
    }
	// pthread_mutex_unlock(philo->time);
    return (((time.tv_sec) * 1000) + (time.tv_usec / 1000));
}
