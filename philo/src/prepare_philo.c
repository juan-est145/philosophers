/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:29:29 by juan              #+#    #+#             */
/*   Updated: 2024/04/05 14:22:44 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_program	*start_mutex(t_program *program);
static t_program	*philo_init_loop(t_program *program);

t_program	*prepare_philo(t_program *program)
{
	program->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* program->num_philo);
	if (program->forks == NULL)
		return (error_msgs(MALLOC_ERROR));
	program->philos = (t_philo *)malloc(sizeof(t_philo) * program->num_philo);
	if (program->philos == NULL)
	{
		free(program->forks);
		return (error_msgs(MALLOC_ERROR));
	}
	if (start_mutex(program) == NULL)
	{
		free(program->forks);
		return (NULL);
	}
	if (philo_init_loop(program) == NULL)
	{
		free(program->forks);
		return (NULL);
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
			return (error_msgs(MUTEX_INIT_ERROR));
	}
	return (program);
}

static t_program	*philo_init_loop(t_program *program)
{
	int				i;
	unsigned long	time;

	i = -1;
	time = get_time();
	if (time == 0)
		return (error_msgs(TIME_FAILURE));
	while (++i < program->num_philo)
	{
		program->philos[i].id = i + 1;
		program->philos[i].left_fork = &program->forks[i];
		program->philos[i].right_fork = &program->forks[(i + 1)
			% program->num_philo];
		program->philos[i].start_time = time;
		program->philos[i].last_ate = time;
		program->philos[i].meals_eaten = 0;
		program->philos[i].philos_full = &program->philos_full;
		program->philos[i].philos_full_mutex = &program->philos_full_mutex;
		program->philos[i].status = &program->philos_status;
		program->philos[i].status_mutex = &program->status_mutex;
		program->philos[i].program = program;
	}
	return (program);
}
