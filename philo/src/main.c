/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:57:18 by thabeck-          #+#    #+#             */
/*   Updated: 2023/06/10 20:55:10 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_philo_env	philo_env;

	if (arguments_are_valid(argc, argv) && \
		init_philo_env(argc, argv, &philo_env))
	{
		init_mutexes(&philo_env);
		philo(&philo_env);
		finish_mutexes(&philo_env);
		printf("%sEnd of Dinner%s\n", C_GREEN, C_RESET);
		return (0);
	}
	return (1);
}
