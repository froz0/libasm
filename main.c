/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:39:27 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/13 18:29:46 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert/assert.h"

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

void	test_strcpy(t_tests *tests)
{
	char	my_dest[300];
	char	sy_dest[300];
	char	*str = "hello";
	char	*str2 = "";
	char	*str3 = "hello libasm";
	
	ft_assert_strcmp(ft_strcpy(my_dest, str), strcpy(sy_dest, str),
			"Compare str with original", tests);
	ft_assert_strcmp(ft_strcpy(my_dest, str2), strcpy(sy_dest, str2),
			"Compare str with original", tests);
	ft_assert_strcmp(ft_strcpy(my_dest, str3), strcpy(sy_dest, str3),
			"Compare str with original", tests);
}

void	test_strlen(t_tests *tests)
{
	char	*str = "Hello world";
	char	*str1 = "Hello\0world";
	char	*str2 = "";
	char	*str3 = "Everyting ok ?";

	ft_assert_cmp(ft_strlen(str), ft_strlen(str),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strlen(str1), ft_strlen(str1),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strlen(str2), ft_strlen(str2),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strlen(str3), ft_strlen(str3),
			"Compare output with original", tests);
}

int	main(int argc, char **argv)
{
	int		log_level = 1;
	t_tests	tests;

	if (argc > 1)
		log_level = atoi(argv[1]);
	else
		printf("No log level specified, set to 1\n");
	tests = init_tester("Libasm tester", log_level);
	tests_header(&tests);
	test_strlen(&tests);
	test_strcpy(&tests);
	tests_result(&tests);
	return (0);
}
