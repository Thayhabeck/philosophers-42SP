/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:26:17 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 20:59:56 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	arguments_are_valid(int argc, char **argv)
{
	int	index;

	if (argc != 5 && argc != 6)
	{
		if (argc < 5)
			printf("%sToo few arguments%s\n", C_RED, C_RESET);
		if (argc > 6)
			printf("%sToo many arguments%s\n", C_RED, C_RESET);
		return (0);
	}
	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) > 11 || !is_digit(argv[index]) || \
			ft_atoi(argv[index]) < 0)
		{
			printf("%s%dst argument isn't a positive int%s\n", C_RED, \
				index, C_RESET);
			return (0);
		}
		index++;
	}
	return (1);
}

int	init_philo_env(int argc, char **argv, t_philo_env *philo_env)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	philo_env->nbr_of_philos = ft_atoi(argv[1]);
	philo_env->time_to_die = ft_atoi(argv[2]);
	philo_env->time_to_eat = ft_atoi(argv[3]);
	philo_env->time_to_sleep = ft_atoi(argv[4]);
	philo_env->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	philo_env->start_time_thread = philo_env->start_time;
	if (argc == 6)
		philo_env->meal_by_philo = ft_atoi(argv[5]);
	else
		philo_env->meal_by_philo = -1;
	philo_env->all_meals = philo_env->meal_by_philo * philo_env->nbr_of_philos;
	if (philo_env->nbr_of_philos == 0 || philo_env->time_to_die == 0 || \
		philo_env->time_to_eat == 0 || philo_env->time_to_sleep == 0 || \
		philo_env->meal_by_philo == 0)
	{
		printf("%sInvalid arguments%s\n", C_RED, C_RESET);
		return (0);
	}
	philo_env->dinner_end = 0;
	return (1);
}
