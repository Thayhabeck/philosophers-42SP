/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:11:14 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 21:06:05 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*observation(void *arg)
{
	t_philo	*philos;
	int		i;
	int		meals_sum;

	philos = (t_philo *)arg;
	i = 0;
	while (!get_dinner_end(philos))
	{
		if (i >= philos->philo_env->nbr_of_philos)
			i = 0;
		if (get_delay(philos->philo_env->start_time) - \
			get_last_meal(&(philos[i])) > philos->philo_env->time_to_die)
			set_dinner_end(philos, i);
		if (philos->philo_env->all_meals >= 0)
			all_meals_eaten(philos, i, &meals_sum);
		i++;
		usleep(4);
	}
	return (NULL);
}

void	set_dinner_end(t_philo *philos, int i)
{
	pthread_mutex_lock(&(philos->philo_env->lock_print));
	printf("%ld %d died\n",
		get_delay(philos->philo_env->start_time), philos[i].index);
	pthread_mutex_lock(&(philos->philo_env->lock_dinner_end));
	philos->philo_env->dinner_end = 1;
	pthread_mutex_unlock(&(philos->philo_env->lock_dinner_end));
	pthread_mutex_unlock(&(philos->philo_env->lock_print));
}

int	get_dinner_end(t_philo *philo)
{
	int	dinner_end;

	pthread_mutex_lock(&(philo->philo_env->lock_dinner_end));
	dinner_end = philo->philo_env->dinner_end;
	pthread_mutex_unlock(&(philo->philo_env->lock_dinner_end));
	return (dinner_end);
}

int	get_last_meal(t_philo *philo)
{
	int	last_meal;

	pthread_mutex_lock(&(philo->lock_last_meal));
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&(philo->lock_last_meal));
	return (last_meal);
}

void	all_meals_eaten(t_philo *philos, int i, int *meals_sum)
{
	pthread_mutex_lock(&(philos[i].lock_meal_count));
	*meals_sum += philos[i].eat_count;
	pthread_mutex_unlock(&(philos[i].lock_meal_count));
	if (i == philos->philo_env->nbr_of_philos - 1)
	{
		if (*meals_sum >= philos->philo_env->all_meals)
		{
			pthread_mutex_lock(&(philos->philo_env->lock_print));
			printf("%sEach philosopher ate %d meals%s\n", C_BLUE, \
				philos->philo_env->meal_by_philo, C_RESET);
			pthread_mutex_lock(&(philos->philo_env->lock_dinner_end));
			philos->philo_env->dinner_end = 1;
			pthread_mutex_unlock(&(philos->philo_env->lock_dinner_end));
			pthread_mutex_unlock(&(philos->philo_env->lock_print));
		}
		*meals_sum = 0;
	}
}
