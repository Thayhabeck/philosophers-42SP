/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:18:32 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 21:12:44 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo(t_philo_env *philo_env)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * philo_env->nbr_of_philos);
	init_philosophers(philos, philo_env);
	dining(philos, philo_env);
	finish_dinner(philos, philo_env);
}

void	init_philosophers(t_philo *philos, t_philo_env *philo_env)
{
	int	index;

	index = 0;
	while (index < philo_env->nbr_of_philos)
	{
		philos[index].index = index + 1;
		philos[index].eat_count = 0;
		philos[index].last_meal = 0;
		philos[index].philo_eat_time = philo_env->time_to_eat;
		philos[index].philo_sleep_time = philo_env->time_to_sleep;
		philos[index].philo_meals = philo_env->meal_by_philo;
		philos[index].unique = philo_env->nbr_of_philos == 1;
		philos[index].left_fork = &philo_env->forks[index];
		philos[index].right_fork = &philo_env->forks[(index + 1) % \
			philo_env->nbr_of_philos];
		philos[index].philo_env = philo_env;
		pthread_mutex_init(&(philos[index].lock_meal_count), NULL);
		pthread_mutex_init(&(philos[index].lock_last_meal), NULL);
		index++;
	}
}

void	dining(t_philo *philos, t_philo_env *philo_env)
{
	pthread_t	*philosophers;
	pthread_t	observer;
	int			index;

	index = 1;
	philosophers = malloc(sizeof(pthread_t) * philo_env->nbr_of_philos);
	while (index < philo_env->nbr_of_philos)
	{
		pthread_create(&philosophers[index], NULL, &philo_routine,
			&philos[index]);
		index += 2;
		if (index >= philo_env->nbr_of_philos && index % 2 == 1)
		{
			usleep(10000);
			index = 0;
		}
	}
	if (philo_env->nbr_of_philos == 1)
		pthread_create(&philosophers[0], NULL, &philo_routine, &philos[0]);
	pthread_create(&observer, NULL, &observation, philos);
	philo_env->philosophers = philosophers;
	philo_env->observer = observer;
}

void	finish_dinner(t_philo *philos, t_philo_env *philo_env)
{
	int	index;

	index = 0;
	pthread_join(philo_env->observer, NULL);
	while (index < philo_env->nbr_of_philos)
	{
		pthread_join(philo_env->philosophers[index], NULL);
		pthread_mutex_destroy(&(philos[index].lock_meal_count));
		pthread_mutex_destroy(&(philos[index].lock_last_meal));
		index++;
	}
	free(philo_env->philosophers);
	free(philos);
}
