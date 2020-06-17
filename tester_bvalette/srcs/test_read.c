/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:46 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 22:29:07 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_READ
////////

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

	printf(GREEN);
	printf("\n\nTest with wrong \n");
	printf(RESET);
	errno = 0;
	ret_ft = ft_read(12056, &buf_ft, buf_size);
	printf("errno :  ft [%d]  | ", errno);
	errno = 0;
	ret_c = read(12056, &buf_ft, buf_size);
	printf("c  [%d]\n", errno);
	printf("return : ft [%d] | c [%d]\n", ret_ft, ret_c);
}
