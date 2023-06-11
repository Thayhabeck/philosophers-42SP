/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:58:06 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 20:33:10 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************************************\
 * INCLUDES
\******************************************************************************/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "./structs.h"

/******************************************************************************\
 * COLORS
\******************************************************************************/
# define C_RED		"\e[38;5;160m"
# define C_BLUE		"\e[38;5;75m"
# define C_GREEN	"\e[38;5;118m"
# define C_RESET	"\e[0m"

/******************************************************************************\
 * arguments.c
\******************************************************************************/
int		arguments_are_valid(int argc, char **argv);
int		init_philo_env(int argc, char **argv, t_philo_env *philo_env);

/******************************************************************************\
 * mutexes.c
\******************************************************************************/
void	init_mutexes(t_philo_env *philo_env);
void	finish_mutexes(t_philo_env *philo_env);

/******************************************************************************\
 * observation.c
\******************************************************************************/
void	*observation(void *arg);
void	set_dinner_end(t_philo *philos, int i);
int		get_dinner_end(t_philo *philo);
int		get_last_meal(t_philo *philo);
void	all_meals_eaten(t_philo *philos, int i, int *meals_sum);

/******************************************************************************\
 * philo_routine.c
\******************************************************************************/
void	*philo_routine(void *arg);
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/******************************************************************************\
 * philo_unique_routine.c
\******************************************************************************/
void	*philo_unique_routine(t_philo *philo);

/******************************************************************************\
 * philo.c
\******************************************************************************/
void	philo(t_philo_env *philo_env);
void	init_philosophers(t_philo *philos, t_philo_env *philo_env);
void	dining(t_philo *philos, t_philo_env *philo_env);
void	finish_dinner(t_philo *philos, t_philo_env *philo_env);

/******************************************************************************\
 * utils.c
\******************************************************************************/
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		is_digit(char *str);
long	get_delay(long initial_time);

#endif
