/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/27 15:06:59 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

static int test_fd(int fd, char *str, int len)
{
	int error = 0;
	int ret_ft = 0;
	int ret_c = 0;
	int errno_ft = 0;
	int errno_c = 0;
		
	printf("\n\nTest with fd = %d and buff %p\n", fd, str);
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
	printf(DARK"errno  : ft [%2d] | c [%2d] ", errno_ft, errno_c);
	if (errno_ft == errno_c)
	{
		printf(GREEN);
		printf("[✅]\n");
	}
	else
	{
		printf(RED);
		printf("[⛔️KO !]\n");
		error++;
	}
	printf(DARK"return : ft [%2d] | c [%2d] ", ret_ft, ret_c);
	if (ret_ft == ret_c)
	{
		printf(GREEN);
		printf("[✅]\n");
	}
	else
	{
		printf(RED);
		printf("[⛔️KO !]\n");
		error++;
	}
	printf(RESET);
	return (error);
}

/////////
// FT_WRITE
////////

int test_ft_write()
{
	int error = 0;

	char *str[5] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
		
	for (int i = 0; i < 5; i++)
		error += test_fd(1, str[i], strlen(str[i]));

	error += test_fd(4242, "yellow!\n", 8);
	error += test_fd(1, "yellow!\n", 8);
	error += test_fd(-1, "Hollow!\n", 8);
	error += test_fd(1, NULL, 8);

	return (error);
}
