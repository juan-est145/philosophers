/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:59 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/27 12:31:06 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program	*philo_arg;

	if (argc >= 5 && argc <= 6)
	{
		philo_arg = parse_arguments(argc, argv);
		if (philo_arg == NULL)
			return (1);
	}
	else
		return (printf("You need to provide at least 4 or 5 arguments\n"), 1);
	return (0);
}
