/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 22:07:30 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_WRITE
////////

void test_ft_write()
{
	int ret_ft = 0;
	int ret_c = 0;

	char *str[5] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
		
	for (int i = 0; i < 5; i++)
	{
		
		ft_write(1, "[", 1);
		ft_write(1, str[i], strlen(str[i]));
		ft_write(1, "]", 1);
		ft_write(1, "\n", 1);
	}
	printf(GREEN);
	printf("Test on fd /tmp/stdout\n");
	printf(RESET);
	int fd = open("/tmp/stdout", O_CREAT | O_WRONLY | O_APPEND, 0666);
	
	for (int i = 0; i < 5; i++)
	{
		ret_ft = ft_write(fd, str[i], strlen(str[i]));
		printf("return : ft [%2d] | errno [%2d]\n", ret_ft, errno);
		ret_c = write(fd, str[i], strlen(str[i]));
		printf("return :  c [%2d] | errno [%2d]\n", ret_c, errno);
	}
	printf(GREEN);
	printf("Test on wrong fd\n");
	printf(RESET);
	fd = 18902;
	ret_ft = ft_write(fd, str[0], strlen(str[0]));
	printf("return : ft [%2d] | errno [%2d]\n", ret_ft, errno);
	ret_c = write(fd, str[0], strlen(str[0]));
	printf("return :  c [%2d] | errno [%2d]\n", ret_c, errno);
}
