/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_deaths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:10:52 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/06 14:24:01 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	check_deaths(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->num_philo)
	{
		if (get_time() - program->philos[i].last_ate >= \
		(unsigned long)program->time_to_die)
		{
			pthread_mutex_lock(&program->status_mutex);
			program->philos_status = DEAD;
			printf("%lu %d died\n", get_time() - program->philos->start_time,
				program->philos[i].id);
			pthread_mutex_unlock(&program->status_mutex);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}

t_status	print_check(t_philo *philo)
{
	pthread_mutex_lock(philo->status_mutex);
	if (*philo->status == DEAD)
	{
		pthread_mutex_unlock(philo->status_mutex);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->status_mutex);
	return (ALIVE);
}