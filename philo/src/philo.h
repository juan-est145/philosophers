/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:41:04 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/26 12:59:56 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	numb_times_to_eat;

}		t_philo;

typedef enum e_errors
{
	INVALID_ARGUMENTS,
	MALLOC_ERROR
}		t_errors;

t_philo	*parse_arguments(int argc, char *argv[]);
void	*error_msgs(t_errors error_type);
