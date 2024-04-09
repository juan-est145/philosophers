/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:54:05 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/09 15:16:12 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup(t_program *program);

// TO DO: Make sure that I include the case where there is only one philo

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
			cleanup(program);
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
	pthread_mutex_destroy(&program->write_mutex);
	while (i < program->num_philo)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->forks);
	free(program->philos);
	free(program);
}
