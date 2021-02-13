/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:53:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/13 14:25:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"

t_tests	init_tester(char name[256], int log_level)
{
	t_tests	tester;

	strcpy(tester.name, name);
	tester.tests_success = 0;
	tester.tests_failed = 0;
	tester.log_level = log_level;
	return (tester);
}

void	tests_header(t_tests *tests)
{
	printf("\033[0m", 1);
	printf("╔╦╦═╦╦══╦══╗╔══╦═╦══╦══╗\n", 1);
	printf("║║║║║╠║║╩╗╔╝╚╗╔╣╦╣══╬╗╔╝\n", 1);
	printf("║║║║║╠║║╗║║  ║║║╩╬══║║║ \n", 1);
	printf("╚═╩╩═╩══╝╚╝  ╚╝╚═╩══╝╚╝ \n", 1);
	printf("\n Name: ", 1);
	printf(tests->name, 1);
	printf("\n Log level: ", 1);
	printf("%i", tests->log_level, 1);
	printf("\033[0m\n\n", 1);
}

void	tests_result(t_tests *tests)
{
	printf("---- [RESULTS] ----\n\n", 1);
	if (tests->tests_failed > 0)
		printf("\033[1;31m", 1);
	else
		printf("\033[1;32m", 1);
	printf("%i", tests->tests_success, 1);
	printf("/", 1);
	printf("%i", tests->tests_success + tests->tests_failed, 1);
	printf("\033[0m\n", 1);
}
