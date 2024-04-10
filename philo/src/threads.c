/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:53:57 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/10 13:51:57 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*init_threads(t_program *program)
{
	pthread_t	observer;
	int			i;

	i = -1;
	while (++i < program->num_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			return (error_msgs(THREAD_ERROR));
	}
	if (pthread_create(&observer, NULL, &observer_routine, program) != 0)
		return (error_msgs(THREAD_ERROR));
	i = -1;
	while (++i < program->num_philo)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (error_msgs(THREAD_JOIN_ERROR));
	}
	if (pthread_join(observer, NULL) != 0)
		return (error_msgs(THREAD_JOIN_ERROR));
	return (program);
}

void	*philo_routine(void *philo)
{
	t_philo	*current_philo;

	current_philo = (t_philo *)philo;
	pthread_mutex_lock(&current_philo->program->time_mutex);
	current_philo->last_ate = get_time();
	pthread_mutex_unlock(&current_philo->program->time_mutex);
	if (current_philo->program->num_philo == 1)
		handle_one_philo(philo);
	if (current_philo->id % 2 == 0)
		even_philo(current_philo);
	else if (current_philo->id % 2 != 0)
		odd_philo(current_philo);
	return (current_philo);
}

void	even_philo(t_philo *philo)
{
	while (*philo->status != DEAD
		&& philo->meals_eaten != philo->program->numb_times_to_eat)
	{
		eat_even(philo);
		rest(philo);
		think(philo);
	}
}

void	odd_philo(t_philo *philo)
{
	while (*philo->status != DEAD
		&& philo->meals_eaten != philo->program->numb_times_to_eat)
	{
		eat_odd(philo);
		rest(philo);
		think(philo);
	}
}

void	*observer_routine(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	while (1)
	{
		if (check_deaths(program) == DEAD
			|| philos_full(program) == true)
			break ;
	}
	return (program);
}
