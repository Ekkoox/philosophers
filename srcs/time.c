/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:51:37 by enschnei          #+#    #+#             */
/*   Updated: 2025/02/10 17:36:45 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int get_time()
{
    struct timeval time;
    
    if(gettimeofday(&time, NULL) == -1)
    {
        perror("Error time receive");
        exit(EXIT_FAILURE);
    }
    return (((time.tv_sec) * 1000) + (time.tv_usec / 1000));
}
