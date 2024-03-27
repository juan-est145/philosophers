/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:19 by juan              #+#    #+#             */
/*   Updated: 2024/03/27 18:33:36 by juan             ###   ########.fr       */
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
	if (pthread_join(observer, NULL) != 0)
		return (error_msgs(THREAD_JOIN_ERROR));
	while (++i < program->num_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			return (error_msgs(THREAD_ERROR));
	}
	i = -1;
	while (++i < program->num_philo)
	{
		program->philos[i].last_ate = get_time();
		if (program->philos[i].last_ate == 0)
			return (error_msgs(TIME_FAILURE));
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (error_msgs(THREAD_JOIN_ERROR));
	}
	return (program);
}

// Fix time for printf
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

void	even_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
	printf("%lu %d is eating\n", get_time(), philo->id);
	usleep(philo->program->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%lu %d is sleeping\n", get_time(), philo->id);
	usleep(philo->program->time_to_sleep * 1000);
}

void	odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
	printf("%lu %d is eating\n", get_time(), philo->id);
	usleep(philo->program->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("%lu %d is sleeping\n", get_time(), philo->id);
	usleep(philo->program->time_to_sleep * 1000);
}

void	*observer_routine(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	while (1)
	{
		if (program->philos_status == DEAD
			|| program->philos_full == program->num_philo)
			break ;
	}
	return (program);
}
