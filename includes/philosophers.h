/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:27:14 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/15 19:21:05 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				philosophers;
	int id;                      // ID du philosophe
	int time_to_eat;             // Temps pour manger
	int time_to_sleep;           // Temps pour dormir
	int time_to_die;             // Temps avant qu'il meure s'il ne mange pas
	pthread_mutex_t *left_fork;  // Mutex pour la fourchette de gauche
	pthread_mutex_t *right_fork; // Mutex pour la fourchette de droite
	pthread_mutex_t	*forks;
}					t_philo;

// ROUTINE
int					destroy_philo(t_philo *philo);
int	                *philosopher_routine(t_philo *philo);
int	                init_philo(t_philo *philo, char **av);

// Parthing
int                 check_arguments(int ac);
int					check_format_arguments(int ac, char **av);

// Utils
int					ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *str);

#endif