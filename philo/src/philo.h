/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:53:48 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/09 15:04:37 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MICRO_SECOND_APROX 920

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
	FORKS
}							t_failed_mutex;

t_program					*parse_arguments(int argc, char *argv[]);
void						*error_msgs(t_errors error_type);
t_program					*prepare_philo(t_program *program);
t_program					*init_threads(t_program *program);
void						*philo_routine(void *philo);
void						even_philo(t_philo *philo);
void						odd_philo(t_philo *philo);
void						*observer_routine(void *arg);
long						get_time(void);
t_status					check_deaths(t_program *program);
t_status					print_check(t_philo *philo);
void						best_usleep(long sleep_time);
void						*mutex_init_error_handler(t_program *program,
								t_failed_mutex failed_mutex, int i);

// Philo actions
void						eat_even(t_philo *philo);
void						eat_odd(t_philo *philo);
void						rest(t_philo *philo);
void						think(t_philo *philo);