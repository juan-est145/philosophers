/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_deaths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:10:52 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/10 14:25:22 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	time_passed_since_last_meal(t_program *program, int i);

t_status	check_deaths(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->num_philo)
	{
		if (time_passed_since_last_meal(program, i) >= program->time_to_die)
		{
			pthread_mutex_lock(&program->status_mutex);
			program->philos_status = DEAD;
			pthread_mutex_unlock(&program->status_mutex);
			pthread_mutex_lock(&program->write_mutex);
			printf("%lu %d died\n", get_time() - program->philos->start_time,
				program->philos[i].id);
			pthread_mutex_unlock(&program->write_mutex);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}

bool	philos_full(t_program *program)
{
	bool	full_philos;

	full_philos = false;
	pthread_mutex_lock(&program->philos_full_mutex);
	if (program->philos_full == program->num_philo)
		full_philos = true;
	pthread_mutex_unlock(&program->philos_full_mutex);
	return (full_philos);
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

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (print_check(philo) == ALIVE)
		print_philo_status("has taken a fork\n", get_time() - philo->start_time,
			philo);
	while (1)
	{
		pthread_mutex_lock(philo->status_mutex);
		if (*philo->status == DEAD)
		{
			pthread_mutex_unlock(philo->status_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->status_mutex);
	}
	pthread_mutex_unlock(philo->right_fork);
}

static long	time_passed_since_last_meal(t_program *program, int i)
{
	long	time_passed;

	pthread_mutex_lock(&program->time_mutex);
	time_passed = get_time() - program->philos[i].last_ate;
	pthread_mutex_unlock(&program->time_mutex);
	return (time_passed);
}
