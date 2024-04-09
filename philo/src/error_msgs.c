/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:53:35 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/09 13:53:42 by juestrel         ###   ########.fr       */
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
