/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:16:53 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 21:09:15 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->unique)
		return (philo_unique_routine(philo));
	while (!get_dinner_end(philo))
	{
		take_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!get_dinner_end(philo))
		printf("%ld %d has taken a fork\n",
			get_delay(philo->philo_env->start_time_thread), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!get_dinner_end(philo))
		printf("%ld %d has taken a fork\n",
			get_delay(philo->philo_env->start_time_thread), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!get_dinner_end(philo))
		printf("%ld %d is eating\n",
			get_delay(philo->philo_env->start_time_thread), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
	pthread_mutex_lock(&(philo->lock_last_meal));
	philo->last_meal = get_delay(philo->philo_env->start_time_thread);
	pthread_mutex_unlock(&(philo->lock_last_meal));
	pthread_mutex_lock(&(philo->lock_meal_count));
	if (philo->eat_count < philo->philo_meals)
		philo->eat_count++;
	pthread_mutex_unlock(&(philo->lock_meal_count));
	usleep(philo->philo_eat_time * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!get_dinner_end(philo))
		printf("%ld %d is sleeping\n",
			get_delay(philo->philo_env->start_time_thread), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
	usleep(philo->philo_sleep_time * 1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!get_dinner_end(philo))
		printf("%ld %d is thinking\n",
			get_delay(philo->philo_env->start_time_thread), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
}
