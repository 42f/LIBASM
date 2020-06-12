/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/12 19:01:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>


/////////
// FT_WRITE
////////


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


/////////
// FT_READ
////////

static void test_ft_read()
{
	unsigned int fd = open("./files/alpha.txt", O_RDONLY);
	int buf_size = 2048;
	char buf[buf_size];

	ft_read(fd, &buf, buf_size);
	printf("%s", buf);
}

/////////
// FT_STRCMP
// non-null argument mandatory on c function
////////

static void test_ft_strcmp()
{
	int nb_test = 5;
	char *str_1[] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};

	char *str_2[] = 
	{
		"hello",
		" ",
		"0hello__",
		"",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
		
	for (int i = 0; i < nb_test; i++)
	{
		printf("[%s]\n[%s]\n", str_1[i], str_2[i]);
		printf(DARK);
		printf("return _ft: %d\nreturn  _c: %d\n", ft_strcmp(str_1[i], str_2[i]), strcmp(str_1[i], str_2[i]));
		if (ft_strcmp(str_1[i], str_2[i]) != strcmp(str_1[i], str_2[i]))
		{
			printf(RED);
			printf("[⛔️KO !]\n\n");
		}
		else
		{
			printf(GREEN);
			printf("[✅]\n\n");
		}
		printf(RESET);
	}
}

/////////
// FT_STRLEN
////////

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

	char *sep = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	printf(RESET);
	printf(GREEN);
	printf("\n%s\n", sep);
	printf("%s\n", sep);
	printf("%*s\n", (int)strlen(sep) / 2 + (int)strlen(str) / 2, str);
	printf("%s\n", sep);
	printf("%s\n\n", sep);

	printf(RESET);
	write(1,RESET, 4);
}

int main(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strlen") == 0))
	{
		print_split("FT_STRLEN");
		test_ft_strlen();
	}
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_write") == 0))
	{
		print_split("FT_WRITE");
		test_ft_write();
	}
		
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_read") == 0))
	{
		print_split("FT_READ");
		test_ft_read();
	}
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcmp") == 0))
	{
		print_split("FT_STRCMP");
		test_ft_strcmp();
	}

	return (0);
}

