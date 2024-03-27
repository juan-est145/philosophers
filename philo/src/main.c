/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:59 by juan_est145       #+#    #+#             */
/*   Updated: 2024/03/27 13:35:15 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program	*program;

	if (argc >= 5 && argc <= 6)
	{
		program = parse_arguments(argc, argv);
		if (program == NULL)
			return (1);
		if (prepare_philo(program) == NULL)
		{
			free(program);
			return (1);
		}
	}
	else
		return (printf("You need to provide at least 4 or 5 arguments\n"), 1);
	return (0);
}
