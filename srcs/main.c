/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:23 by enschnei          #+#    #+#             */
/*   Updated: 2024/09/05 19:17:47 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	// t_philo *philo;
	(void)av;

	if (ac != 6)
		ft_putstr_fd("Error arguments\n", 2);
	check_format(ac, av);
	return (0);
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// // Variable partagée
// int shared_variable = 0;
// // Mutex pour synchroniser l'accès à la variable partagée
// pthread_mutex_t mutex;

// // Fonction exécutée par chaque thread
// void* increment_function() {
//     for (int i = 0; i < 10000000; ++i) {
//         // Verrouiller le mutex avant de modifier la variable partagée
//         pthread_mutxe_lock(&mutex);
//         shared_variable++;
//         // Déverrouiller le mutex après modification
//         pthread_mutex_unlock(&mutex);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t thread1, thread2;

//     // Initialiser le mutex
//     pthread_mutex_init(&mutex, NULL);

//     // Créer deux threads
//     if (pthread_create(&thread1, NULL, increment_function, NULL) != 0) {
//         perror("Failed to create thread 1");
//         return 1;
//     }
//     if (pthread_create(&thread2, NULL, increment_function, NULL) != 0) {
//         perror("Failed to create thread 2");
//         return 1;
//     }

//     // Attendre que les deux threads se terminent
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     // Détruire le mutex
//     pthread_mutex_destroy(&mutex);

//     // Afficher la valeur de la variable partagée
//     printf("Final value of shared variable: %d\n", shared_variable);

//     return 0;
// }
