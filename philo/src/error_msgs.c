/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:55:22 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/26 12:59:46 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*error_msgs(t_errors error_type)
{
	if (error_type == INVALID_ARGUMENTS)
		printf("Invalid arguments, exiting program\n");
	else if (error_type == MALLOC_ERROR)
		printf("Error in malloc, exiting program\n");
	return (NULL);
}
