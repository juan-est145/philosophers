/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-est145 <juan-est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:53:48 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/22 19:34:51 by juan-est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MICRO_SECOND_APROX 920

typedef struct s_program	t_program;
typedef struct s_philo		t_philo;

typedef enum e_status
{
	DEAD,
	ALIVE
}							t_status;

typedef struct s_philo
{
	pthread_t				thread;
	int						id;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	long					last_ate;
	long					start_time;
	int						meals_eaten;
	int						*philos_full;
	pthread_mutex_t			*philos_full_mutex;
	t_status				*status;
	pthread_mutex_t			*status_mutex;
	pthread_mutex_t			*write_mutex;
	t_program				*program;
	pthread_mutex_t			*time_mutex;
}							t_philo;

typedef struct s_program
{
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						numb_times_to_eat;
	int						philos_full;
	pthread_mutex_t			philos_full_mutex;
	t_philo					*philos;
	pthread_mutex_t			*forks;
	t_status				philos_status;
	pthread_mutex_t			status_mutex;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			time_mutex;
}							t_program;

typedef enum e_errors
{
	INVALID_ARGUMENTS,
	MALLOC_ERROR,
	MUTEX_INIT_ERROR,
	THREAD_ERROR,
	THREAD_JOIN_ERROR,
	TIME_FAILURE
}							t_errors;

typedef enum e_failed_mutex
{
	STATUS_MUTEX,
	WRITE_MUTEX,
	TIME_MUTEX,
	FORKS
}							t_failed_mutex;

// Utilities
long						get_time(void);
void						destroy_mutex_forks(t_program *program, int index);

// Init philos
t_program					*parse_arguments(int argc, char *argv[]);
t_program					*prepare_philo(t_program *program);
t_program					*init_threads(t_program *program);

// Error handling
void						*error_msgs(t_errors error_type);
void						*mutex_init_error_handler(t_program *program,
								t_failed_mutex failed_mutex, int i);
// Philo functions
void						handle_one_philo(t_philo *philo);
void						eat_even(t_philo *philo);
void						eat_odd(t_philo *philo);
void						rest(t_philo *philo);
void						think(t_philo *philo);
void						*philo_routine(void *philo);
void						even_philo(t_philo *philo);
void						odd_philo(t_philo *philo);
void						print_philo_status(char *message, long time,
								t_philo *philo);
t_status					print_check(t_philo *philo);
void						best_usleep(long sleep_time);

// Observer functions
void						*observer_routine(void *arg);
t_status					check_deaths(t_program *program);
bool						philos_full(t_program *program);
#endif