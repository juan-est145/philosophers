/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:19 by juan              #+#    #+#             */
/*   Updated: 2024/04/05 19:44:20 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*init_threads(t_program *program)
{
	pthread_t	observer;
	int			i;

	i = -1;
	if (pthread_create(&observer, NULL, &observer_routine, program) != 0)
		return (error_msgs(THREAD_ERROR));
	while (++i < program->num_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			return (error_msgs(THREAD_ERROR));
	}
	if (pthread_join(observer, NULL) != 0)
		return (error_msgs(THREAD_JOIN_ERROR));
	i = -1;
	while (++i < program->num_philo)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (error_msgs(THREAD_JOIN_ERROR));
	}
	return (program);
}

// Check that philo has not and will not die
void	*philo_routine(void *philo)
{
	t_philo	*current_philo;

	current_philo = (t_philo *)philo;
	if (current_philo->id % 2 == 0)
		even_philo(current_philo);
	else if (current_philo->id % 2 != 0)
		odd_philo(current_philo);
	return (current_philo);
}
// Need to add a printf message of when has started to think
// Also, need to improve

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

// Need to add a printf message of when has started to think

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
			|| program->philos_full == program->num_philo)
			break ;
	}
	return (program);
}
