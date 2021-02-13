/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:39:27 by tmatis            #+#    #+#             */
/*   Updated: 2021/02/13 22:32:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "assert/assert.h"

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);

void	test_write(t_tests	*tests)
{
	int	ret;
	(void)tests;
	char	*str = "hello\n";
	ret = ft_write(50, str, 3);
	printf("ret: %i\n", ret);
}	
void	test_strcmp(t_tests *tests)
{
	char	*str1 = "Hello world";
	char	*str2 = "";
	char	*str3 = "Hello";
	char	*str4 = "Nothing";

	ft_assert_cmp(ft_strcmp(str1, str1), strcmp(str1, str1),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str1, str2), strcmp(str1, str2),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str2, str1), strcmp(str2, str1),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str3, str1), strcmp(str3, str1),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str3, str4), strcmp(str3, str4),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str4, str3), strcmp(str4, str3),
			"Compare output with original", tests);
	ft_assert_cmp(ft_strcmp(str2, str2), strcmp(str2, str2),
			"Compare output with original", tests);
}

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
	test_strcmp(&tests);
	test_write(&tests);
	tests_result(&tests);
	return (0);
}
