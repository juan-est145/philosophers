/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:41:04 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/27 12:49:02 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_status
{
	DEAD,
	ALIVE
}					t_status;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	t_status		status;

}					t_philo;

typedef struct s_program
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numb_times_to_eat;
	pthread_mutex_t	*forks;
}					t_program;

typedef enum e_errors
{
	INVALID_ARGUMENTS,
	MALLOC_ERROR
}					t_errors;

t_program			*parse_arguments(int argc, char *argv[]);
void				*error_msgs(t_errors error_type);
