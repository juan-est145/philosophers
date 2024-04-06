/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:58:00 by juan              #+#    #+#             */
/*   Updated: 2024/04/06 17:30:06 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long		get_time_elapsed(struct timeval start, struct timeval current);

unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	best_usleep(long sleep_time)
{
	struct timeval	start;
	struct timeval	current;
	long			time_elapsed;
	long			time_rem;

	gettimeofday(&start, NULL);
	time_elapsed = 0;
	time_rem = 0;
	while (time_elapsed < sleep_time)
	{
		gettimeofday(&current, NULL);
		time_elapsed = get_time_elapsed(start, current);
		time_rem = time_elapsed - sleep_time;
		if (time_rem > 1000)
			usleep(time_rem / 2);
	}
}

static long	get_time_elapsed(struct timeval start, struct timeval current)
{
	return ((current.tv_sec - start.tv_sec) * 1000000UL + (current.tv_usec
			- start.tv_usec));
}
