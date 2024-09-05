/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:27:14 by enschnei          #+#    #+#             */
/*   Updated: 2024/09/05 19:43:55 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct s_philo
{
	int i;
}				t_philo;

//Parthing
int check_format(int ac, char **av);

//Utils
int	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);

#endif