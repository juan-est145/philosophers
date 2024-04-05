/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:28 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/05 14:30:56 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("%lu %d has taken a fork\n", get_time() - philo->start_time,
		philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("%lu %d has taken a fork\n", get_time() - philo->start_time,
		philo->id);
	printf("%lu %d is eating\n", get_time() - philo->start_time, philo->id);
	usleep(philo->program->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%lu %d is sleeping\n", get_time() - philo->start_time, philo->id);
	usleep(philo->program->time_to_sleep * 1000);
}

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%lu %d has taken a fork\n", get_time() - philo->start_time,
		philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%lu %d has taken a fork\n", get_time() - philo->start_time,
		philo->id);
	printf("%lu %d is eating\n", get_time() - philo->start_time, philo->id);
	usleep(philo->program->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("%lu %d is sleeping\n", get_time() - philo->start_time, philo->id);
	usleep(philo->program->time_to_sleep * 1000);
}
