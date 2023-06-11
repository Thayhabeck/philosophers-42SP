/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_unique_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:25:01 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 21:10:24 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_unique_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&(philo->philo_env->lock_print));
	if (!philo->philo_env->dinner_end)
		printf("%ld %d has taken a fork\n",
			get_delay(philo->philo_env->start_time), philo->index);
	pthread_mutex_unlock(&(philo->philo_env->lock_print));
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}
