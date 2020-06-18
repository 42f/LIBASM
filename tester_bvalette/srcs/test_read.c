/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:46 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/18 12:40:33 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_READ
////////

static void test_fd(int fd, int buf_size, char *buf_ft, char *buf_c)
{
	int ret_ft = 0;
	int ret_c = 0;
	int errno_ft = 0;
	int errno_c = 0;
		
	printf(GREEN);
	printf("\n\nTest with fd = %d \n", fd);
	printf(RESET);
	errno = 0;
	ret_ft = ft_read(fd, &buf_ft, buf_size);
	errno_ft = errno;	
	errno = 0;
	ret_c = read(fd, &buf_c, buf_size);
	errno_c = errno;
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


void test_ft_read()
{
	unsigned int fd = open("./files/alpha3.txt", O_RDONLY);
	int buf_size = 2048;
	char buf_ft[buf_size];
	char buf_c[buf_size];
	int ret_ft = 0;
	int ret_c = 0;
	
	errno = 0;
	ret_c = read(fd, &buf_c, buf_size);
	printf("C  funciton \nreturn [%d]\n", ret_c);
	printf("errno [%d]\n", errno);
	printf(DARK);
	printf("buff =\n%s\n\n", buf_c);
	close(fd);
	printf(RESET);
	errno = 0;

	fd = open("./files/alpha3.txt", O_RDONLY);
	ret_ft = ft_read(fd, &buf_ft, buf_size);
	printf("FT funciton \nreturn [%d]\n", ret_ft);
	printf("errno [%d]\n\n", errno);
	printf(DARK);
	printf("buff =\n%s\n\n", buf_ft);
	printf(RESET);

	test_fd(12345, buf_size, buf_ft, buf_c);
	test_fd(-1, buf_size, buf_ft, buf_c);

}
