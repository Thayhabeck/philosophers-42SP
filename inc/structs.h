/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:35:27 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 20:52:44 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * INCLUDES
\******************************************************************************/
# include <pthread.h>

/******************************************************************************\
 * PHILO APP ENVIRONMENT
\******************************************************************************/
typedef struct s_philo_env
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_by_philo;
	int				all_meals;
	long			start_time;
	long			start_time_thread;
	int				dinner_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_print;
	pthread_t		*philosophers;
	pthread_t		observer;
	pthread_mutex_t	lock_dinner_end;
}	t_philo_env;

/******************************************************************************\
 * PHILOSOPHER
\******************************************************************************/
typedef struct s_philo
{
	int				index;
	int				eat_count;
	long			last_meal;
	int				unique;
	int				philo_eat_time;
	int				philo_sleep_time;
	int				philo_meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo_env		*philo_env;
	pthread_mutex_t	lock_meal_count;
	pthread_mutex_t	lock_last_meal;
}	t_philo;

#endif
