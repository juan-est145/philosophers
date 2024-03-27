/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:55:22 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/27 17:57:49 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*error_msgs(t_errors error_type)
{
	if (error_type == INVALID_ARGUMENTS)
		printf("Invalid arguments, exiting program\n");
	else if (error_type == MALLOC_ERROR)
		printf("Error in malloc, exiting program\n");
	else if (error_type == MUTEX_INIT_ERROR)
		printf("Error in mutex initialization, exiting program\n");
	else if (error_type == THREAD_ERROR)
		printf("Error in thread creation, exiting program\n");
	else if (error_type == THREAD_JOIN_ERROR)
		printf("Error in thread join, exiting program\n");
	else if (error_type == TIME_FAILURE)
		printf("Error getting the current time, exiting program\n");
	return (NULL);
}
