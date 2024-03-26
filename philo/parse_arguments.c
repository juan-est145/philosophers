/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:49:09 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/26 11:37:16 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_constructor(t_philo *philo_arg, int argc, char *argv[]);
static int	ft_atoi(char *str);

t_philo	*parse_arguments(int argc, char *argv[])
{
	int		i;
	int		j;
	t_philo	*philo_arg;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (NULL);
		}
		j++;
	}
	philo_arg = (t_philo *)malloc(sizeof(t_philo));
	if (philo_arg == NULL)
		return (NULL);
	return (philo_constructor(philo_arg, argc, argv), philo_arg);
}

static void	philo_constructor(t_philo *philo_arg, int argc, char *argv[])
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
	if (argc == 6)
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
