/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:54:50 by juestrel          #+#    #+#             */
/*   Updated: 2024/04/10 14:40:05 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	arg_constructor(t_program *philo_arg, int argc, char *argv[]);
static int	ft_atoi(char *str);

t_program	*parse_arguments(int argc, char *argv[])
{
	int			i;
	int			j;
	t_program	*philo_arg;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][0] == '0')
				return (error_msgs(INVALID_ARGUMENTS));
			i++;
		}
		j++;
	}
	philo_arg = (t_program *)malloc(sizeof(t_program));
	if (philo_arg == NULL)
		return (error_msgs(MALLOC_ERROR));
	return (arg_constructor(philo_arg, argc, argv), philo_arg);
}

static void	arg_constructor(t_program *philo_arg, int argc, char *argv[])
{
	int	args[5];
	int	i;
	int	arg_iter;

	i = 1;
	arg_iter = 0;
	while (i < argc)
	{
		args[arg_iter] = ft_atoi(argv[i]);
		arg_iter++;
		i++;
	}
	if (argc == 5)
		args[4] = -1;
	philo_arg->num_philo = args[0];
	philo_arg->time_to_die = args[1];
	philo_arg->time_to_eat = args[2];
	philo_arg->time_to_sleep = args[3];
	philo_arg->numb_times_to_eat = args[4];
}

static int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}
