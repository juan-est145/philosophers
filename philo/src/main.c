/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:59 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/26 11:36:41 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo_arg;

	if (argc >= 5 && argc <= 6)
	{
		philo_arg = parse_arguments(argc, argv);
		(void)philo_arg;
	}
	else
		printf("You need to provide at least 4 arguments\n");
	return (0);
}
