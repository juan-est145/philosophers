/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:28 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/10 12:30:10 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_philo_status(char *message, long time, t_philo *philo);

void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (print_check(philo) == ALIVE)
		print_philo_status("has taken a fork\n", get_time() - philo->start_time,
			philo);
	pthread_mutex_lock(philo->right_fork);
	if (print_check(philo) == ALIVE)
		print_philo_status("has taken a fork\n", get_time() - philo->start_time,
			philo);
	if (print_check(philo) == ALIVE)
		print_philo_status("is eating\n", get_time() - philo->start_time,
			philo);
	philo->last_ate = get_time();
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->program->numb_times_to_eat)
	{
		pthread_mutex_lock(philo->philos_full_mutex);
		philo->program->philos_full++;
		pthread_mutex_unlock(philo->philos_full_mutex);
	}
	best_usleep((long)philo->program->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (print_check(philo) == ALIVE)
		print_philo_status("has taken a fork\n", get_time() - philo->start_time,
			philo);
	if (philo->program->num_philo == 1)
		handle_one_philo(philo);
	pthread_mutex_lock(philo->left_fork);
	if (print_check(philo) == ALIVE)
		print_philo_status("has taken a fork\n", get_time() - philo->start_time,
			philo);
	if (print_check(philo) == ALIVE)
		print_philo_status("is eating\n", get_time() - philo->start_time,
			philo);
	philo->last_ate = get_time();
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->program->numb_times_to_eat)
	{
		pthread_mutex_lock(philo->philos_full_mutex);
		philo->program->philos_full++;
		pthread_mutex_unlock(philo->philos_full_mutex);
	}
	best_usleep((long)philo->program->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	rest(t_philo *philo)
{
	if (print_check(philo) == ALIVE)
		print_philo_status("is sleeping\n", get_time() - philo->start_time,
			philo);
	best_usleep((long)philo->program->time_to_sleep);
}

void	think(t_philo *philo)
{
	if (print_check(philo) == ALIVE)
		print_philo_status("is thinking\n", get_time() - philo->start_time,
			philo);
	if (philo->program->num_philo % 2 != 0)
		best_usleep((philo->program->time_to_eat * 2)
			- philo->program->time_to_sleep);
}
// time_to_think = (time_to_eat * 2) - time_to_sleep)

static void	print_philo_status(char *message, long time, t_philo *philo)
{
	pthread_mutex_lock(philo->write_mutex);
	printf("%lu %d %s", time, philo->id, message);
	pthread_mutex_unlock(philo->write_mutex);
}
