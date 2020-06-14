/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/14 22:59:29 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>
#include <errno.h>

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
// FT_STRCPY
// non-null argument mandatory on c function
////////

static void test_ft_strcpy()
{
	int nb_test = 5;
	char *ret_ft = NULL;
	char *ret_c = NULL;
	char *str_1[] = 
	{
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};

	char *str_2[nb_test];
	for (int i = 0; i < nb_test; i++)
	{
		str_2[i] = (char*)malloc(sizeof(char) * (strlen(str_1[i]) + 1));
		if (str_2[i] == NULL)
			return ;
		printf("FOR FT_STRCPY. Just malloced %p\n", str_2[i]);
	}
	
	char *str_3[nb_test];
	for (int i = 0; i < nb_test; i++)
	{
		str_3[i] = (char*)malloc(sizeof(char) * (strlen(str_1[i]) + 1));
		if (str_3[i] == NULL)
			return ;
		printf("FOR STRCPY. Just malloced %p\n", str_3[i]);
	}	
	
	for (int i = 0; i < nb_test; i++)
	{
		ret_ft = ft_strcpy(str_2[i], str_1[i]); 
		ret_c =  strcpy(str_3[i], str_1[i]);
		if (ret_ft == str_2[i] && strcmp(ret_ft, str_1[i]) == 0)
		{
			printf(GREEN);
			printf("\n\n[✅] ");
		}
		else
		{
			printf(RED);
			printf("\n\n[⛔️KO !] ");
		}
		printf(RESET);
		printf("FT_ \n  src[%s]\n=>dst[%s]\n", str_1[i], ret_ft);
		printf(DARK);
		printf("C_  \n  src[%s]\n=>dst[%s]\n\n", str_1[i], ret_c);
		printf("return _ft: \ndst before{%p} \ndst after (%p)\nreturn  _c: \ndst before{%p} \ndst after (%p)\n", str_2[i], ret_ft, str_3[i], ret_c);

		free(str_3[i]);
		free(str_2[i]);
		}
}

/////////
// FT_STRCMP
// non-null argument mandatory on c function
////////

static void test_ft_strcmp()
{
	int nb_test = 6;
	char *str_1[] = 
	{
		"\50",
		"hello",
		"",
		"0hello",
		" ",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};

	char *str_2[] = 
	{
		"\210",
		"hello",
		" ",
		"0hello__",
		"",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwhello"
	};
	int ret_c = 0;
	int ret_ft = 0;
	
	for (int i = 0; i < nb_test; i++)
	{
		printf("[%s]\n[%s]\n", str_1[i], str_2[i]);
		printf(DARK);
		ret_ft = ft_strcmp(str_1[i], str_2[i]); 
		ret_c =  strcmp(str_1[i], str_2[i]);
		printf("return _ft: %d\nreturn  _c: %d\n", ret_ft, ret_c);
		if (ret_ft != ret_c)
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

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcpy") == 0))
	{
		print_split("FT_STRCMP");
		test_ft_strcpy();
	}

	return (0);
}

