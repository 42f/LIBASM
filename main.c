/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/11 23:20:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>

static void test_ft_write()
{
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
}


static void test_ft_read()
{
	unsigned int fd = open("./files/alpha.txt", O_RDONLY);
	int buf_size = 2048;
	char buf[buf_size];

	ft_read(fd, &buf, buf_size);
	printf("%s", buf);
}

static void test_ft_strlen()
{
	char *str[5] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
		
	for (int i = 0; i < 5; i++)
		printf("[%s]\nlen = %d | %lu\n\n", str[i], ft_strlen(str[i]), strlen(str[i]));
}

void	print_split(char *str)
{
	printf(RESET);
	printf(GREEN);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("       ==================== %s ================\n", str);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf(RESET);
	write(1,RESET, 4);
}


int main()
{
	print_split("FT_STRLEN");
	test_ft_strlen();
	
	print_split("FT_WRITE");
	test_ft_write();
	
	print_split("FT_READ");
	test_ft_read();

	return (0);
}

