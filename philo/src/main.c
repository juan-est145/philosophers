/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:59 by juan_est145       #+#    #+#             */
/*   Updated: 2024/04/06 15:19:34 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup(t_program *program);

int	main(int argc, char *argv[])
{
	t_program	*program;

	if (argc >= 5 && argc <= 6)
	{
		program = parse_arguments(argc, argv);
		if (program == NULL)
			return (1);
		if (prepare_philo(program) == NULL)
		{
			free(program);
			return (1);
		}
		if (init_threads(program) == NULL)
		{
			free(program->philos);
			free(program);
			return (1);
		}
		cleanup(program);
	}
	else
		return (printf("You need to provide at least 4 or 5 arguments\n"), 1);
	return (0);
}

static void	cleanup(t_program *program)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->philos_full_mutex);
	pthread_mutex_destroy(&program->status_mutex);
	while (i < program->num_philo)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->forks);
	free(program->philos);
	free(program);
}
