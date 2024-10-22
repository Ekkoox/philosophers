/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:27:14 by enschnei          #+#    #+#             */
/*   Updated: 2024/10/22 19:19:36 by enschnei         ###   ########.fr       */
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
	int				id;
	unsigned int				time_to_eat;
	unsigned int				time_to_sleep;
	unsigned int				time_to_die;
	int 			meals_count;
	unsigned int	startTime;
	unsigned int	lastEatTime;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t meals_mutex;
	pthread_t		thread;
	// t_time			*time;
}					t_philo;

// Time
unsigned int 				get_time();

// Routine
int					join_philo(t_philo *philo);
int					destroy_philo(t_philo *philo);
int					init_philo(t_philo *philo, char **av);
void				*philosopher_routine(void *param);

// Parthing
int					check_arguments(int ac);
int					check_format_arguments(int ac, char **av);

// Utils
int					ft_atoi(const char *str);
int					ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);

#endif