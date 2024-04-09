/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:54:25 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/09 13:54:27 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_program	*start_mutex(t_program *program);
static t_program	*philo_init_loop(t_program *program);
static void			destroy_mutex_forks(t_program *program, int index);
static void			destroy_all_mutexs(t_program *program);

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
		free(program->philos);
		free(program->forks);
		return (NULL);
	}
	if (philo_init_loop(program) == NULL)
	{
		destroy_all_mutexs(program);
		free(program->philos);
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
	{
		pthread_mutex_destroy(&program->philos_full_mutex);
		return (error_msgs(MUTEX_INIT_ERROR));
	}
	while (++i < program->num_philo)
	{
		if (pthread_mutex_init(&program->forks[i], NULL) != 0)
		{
			pthread_mutex_destroy(&program->philos_full_mutex);
			pthread_mutex_destroy(&program->status_mutex);
			destroy_mutex_forks(program, i - 1);
			return (error_msgs(MUTEX_INIT_ERROR));
		}
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

static void	destroy_mutex_forks(t_program *program, int index)
{
	while (index >= 0)
	{
		pthread_mutex_destroy(&program->forks[index]);
		index--;
	}
}

static void	destroy_all_mutexs(t_program *program)
{
	pthread_mutex_destroy(&program->philos_full_mutex);
	pthread_mutex_destroy(&program->status_mutex);
	destroy_mutex_forks(program, program->num_philo - 1);
}
