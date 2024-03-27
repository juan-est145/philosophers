/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:19 by juan              #+#    #+#             */
/*   Updated: 2024/03/27 18:02:34 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*init_threads(t_program *program)
{
	pthread_t		observer;
	unsigned int	i;

	i = -1;
	if (ptrhead_create(&observer, NULL, &observer_routine, program) != 0)
		return (error_msgs(THREAD_ERROR));
	if (pthread_join(observer, NULL) != 0)
		return (error_msgs(THREAD_JOIN_ERROR));
	while (++i < program->num_philo)
	{
		program->philos[i].last_ate = get_time();
		if (program->philos[i].last_ate == NULL)
			return (error_msgs(TIME_FAILURE));
		return (error_msgs(TIME_FAILURE));
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			return (error_msgs(THREAD_ERROR));
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (error_msgs(THREAD_JOIN_ERROR));
	}
	return (program);
}

void	philo_routine(t_philo *philo)
{
	(void)philo;
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
