/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:29:29 by juan              #+#    #+#             */
/*   Updated: 2024/03/27 14:15:36 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_program	*start_mutex(t_program *program);


//TO DO: Time and adding data to last ate property of philo
t_program	*prepare_philo(t_program *program)
{
	int	i;

	i = -1;
	program->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* program->num_philo);
	if (program->forks == NULL)
		return (error_msgs(MALLOC_ERROR));
	if (start_mutex(program) == NULL)
		return (NULL);
	while (++i < program->num_philo)
	{
		program->philos[i].id = i + 1;
		program->philos[i].left_fork = &program->forks[i];
		program->philos[i].right_fork = &program->forks[(i + 1)
			% program->num_philo];
		program->philos[i].meals_eaten = 0;
		program->philos[i].philos_full = &program->philos_full;
		program->philos[i].philos_full_mutex = &program->philos_full_mutex;
		program->philos[i].status = &program->philos_status;
		program->philos[i].status_mutex = &program->status_mutex;
	}
	return (program);
}

static t_program	*start_mutex(t_program *program)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&program->philos_full_mutex, NULL) != 0)
		return (error_msgs(MUTEX_INIT_ERROR));
	program->philos_status = ALIVE;
	if (pthread_mutex_init(&program->status_mutex, NULL) != 0)
		return (error_msgs(MUTEX_INIT_ERROR));
	while (++i < program->num_philo)
	{
		if (pthread_mutex_init(&program->forks[i], NULL) != 0)
		{
			free(program->forks);
			return (error_msgs(MUTEX_INIT_ERROR));
		}
	}
	return (program);
}
