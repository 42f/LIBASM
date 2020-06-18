/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/18 13:55:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

static void test_fd(int fd, char *str, int len)
{
	int ret_ft = 0;
	int ret_c = 0;
	int errno_ft = 0;
	int errno_c = 0;
		
	printf(GREEN);
	printf("\n\nTest with fd = %d \n", fd);
	printf(RESET);
	write(fd, "[", 1);
	errno = 0;
	ret_c = write(fd, str, len);
	errno_c = errno;
	write(fd, "]\n[", 3);
	errno = 0;
	ret_ft = ft_write(fd, str, len);
	errno_ft = errno;	
	write(fd, "]\n", 2);
	printf("c  [%d]\n", errno);
	printf("errno  : ft [%2d] | c [%2d] ", errno_ft, errno_c);
	if (errno_ft == errno_c)
	{
		printf(GREEN);
		printf("[✅]\n");
	}
	else
	{
		printf(RED);
		printf("[⛔️KO !]\n");
	}
	printf(RESET);
	printf("return : ft [%2d] | c [%2d] ", ret_ft, ret_c);
	if (ret_ft == ret_c)
	{
		printf(GREEN);
		printf("[✅]\n");
	}
	else
	{
		printf(RED);
		printf("[⛔️KO !]\n");
	}
	printf(RESET);
}

/////////
// FT_WRITE
////////

void test_ft_write()
{
	char *str[5] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
		
	test_fd(4242, "yellow!\n", 8);
	for (int i = 0; i < 5; i++)
		test_fd(1, str[i], strlen(str[i]));
	test_fd(1, "yellow!\n", 8);
	test_fd(-1, "Hollow!\n", 8);
}
