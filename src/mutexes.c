/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:51:05 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 21:03:36 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_mutexes(t_philo_env *philo_env)
{
	int	index;

	index = 0;
	philo_env->forks = malloc(sizeof(pthread_mutex_t) * \
		philo_env->nbr_of_philos);
	while (index < philo_env->nbr_of_philos)
	{
		pthread_mutex_init(&philo_env->forks[index], NULL);
		index++;
	}
	pthread_mutex_init(&philo_env->lock_print, NULL);
	pthread_mutex_init(&philo_env->lock_dinner_end, NULL);
}

void	finish_mutexes(t_philo_env *philo_env)
{
	int	index;

	index = 0;
	while (index < philo_env->nbr_of_philos)
	{
		pthread_mutex_destroy(&philo_env->forks[index]);
		index++;
	}
	pthread_mutex_destroy(&philo_env->lock_print);
	pthread_mutex_destroy(&philo_env->lock_dinner_end);
	free(philo_env->forks);
}
