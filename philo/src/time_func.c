/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:54:32 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/09 13:54:34 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	best_usleep(long sleep_time)
{
	long	time;

	time = get_time();
	usleep(sleep_time * MICRO_SECOND_APROX);
	while (get_time() < time + sleep_time)
		usleep(sleep_time * 3);
}
