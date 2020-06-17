/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 09:31:30 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
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
/// FT_STRCPY long test
////////

static void test_ft_strcpy_long()
{

	char *ret_ft = NULL;
	char *ret_c = NULL;
	size_t buf_size = 1000000000;
	char *str_1 = NULL;
	char *str_2 = NULL;
	char *str_3 = NULL;
	int fd = 0;
	int ret = 0;
	size_t len = 0;

	fd = open("./files/large_file.txt", O_RDONLY);
	if (fd <= 2)
	{
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return ;
	}
	str_1 = (char *)calloc(sizeof(char), buf_size + 1);
	ret = read(fd, str_1, buf_size);
	if (ret < 0)
	{
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return ;
	}
	close(fd);
	len = strlen(str_1);
	str_2 = (char*)malloc(sizeof(char) * (len + 1));
	str_3 = (char*)malloc(sizeof(char) * (len + 1));
	if (str_2 == NULL || str_3 == NULL)
	{
		printf(RED);
		printf("ERROR MALLOC");
		printf(RESET);
		return ;
	}
	printf("FOR FT_STRCPY. Just malloced %p\n", str_2);
	printf("FOR    STRCPY. Just malloced %p\n", str_3);
	
	
	ret_ft = ft_strcpy(str_2, str_1); 
	ret_c =  strcpy(str_3, str_1);
	
	if (ret_ft == str_2 && strncmp(ret_ft, ret_c, len + 1) == 0)
	{
		printf(GREEN);
		printf("\n\n[✅] For very long string\n");
	}
	else
	{
		printf(RED);
		printf("\n\n[⛔️KO !] For very long string\n");
	}
	printf(RESET);
	len = strlen(ret_ft) - 10;
	printf("FT_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len, ret_ft, len);
	printf(DARK);
	printf(" C_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len, ret_c, len);
	printf("return _ft: \ndst before{%p} \ndst after (%p)\nreturn  _c: \ndst before{%p} \ndst after (%p)\n", str_2, ret_ft, str_3, ret_c);

	free(str_1);
	free(str_3);
	free(str_2);
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
		printf("return _ft: \ndst before{%p} \ndst after (%p)\nreturn  _c: \ndst before{%p} \ndst after (%p)\n\n", str_2[i], ret_ft, str_3[i], ret_c);

		free(str_3[i]);
		free(str_2[i]);
		}
		printf(RESET);
		////////
		/// TEST VERY LONG STRING
		///////
		test_ft_strcpy_long();
}

/////////
/// FT_STRCMP long test
////////

static void test_ft_strcmp_long()
{

	size_t buf_size = 1000000000;
	char *str_1[2];
	int fd = 0;
	int ret = 0;
	int ret_ft = 0;
	int ret_c = 0;
	size_t len = 0;

	for (int i = 0; i < 2; i++)
	{
		fd = open("./files/large_file.txt", O_RDONLY);
		if (fd <= 2)
		{
			printf(RED);
			printf("ERROR FILE TEST");
			printf(RESET);
			return ;
		}
		str_1[i] = (char *)calloc(sizeof(char), buf_size + 1);
		ret = read(fd, str_1[i], buf_size);
		if (ret < 0)
		{
			printf(RED);
			printf("ERROR FILE TEST");
			printf(RESET);
			return ;
		}
		close(fd);
		fd = 0;
	}

	len = strlen(str_1[1]);
	
	ret_ft = ft_strcmp(str_1[0], str_1[1]); 
	ret_c = strcmp(str_1[0], str_1[1]); 
	
	if (ret_ft == ret_c)
	{
		printf(GREEN);
		printf("\n\n[✅] For very long string\n");
	}
	else
	{
		printf(RED);
		printf("\n\n[⛔️KO !] For very long string\n");
	}
	printf(RESET);
	printf("FT_ returns %d \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", ret_ft, str_1[0], len - 10, str_1[1], len - 10);
	printf(DARK);
	printf(" C_ returns %d \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", ret_c, str_1[0], len - 10, str_1[1], len - 10);
	free(str_1[1]);
	free(str_1[0]);
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
		ret_ft = ft_strcmp(str_1[i], str_2[i]); 
		ret_c =  strcmp(str_1[i], str_2[i]);
		printf(DARK);
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
	test_ft_strcmp_long();
}

/////////
// FT_STRLEN
////////

static void test_ft_strlen()
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
		ret_ft = ft_strlen(str[i]);
		ret_c = strlen(str[i]);
		printf("[%s]\nlen = %d | %lu   -- ", str[i], ft_strlen(str[i]), strlen(str[i]));
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



void	print_split(char *str)
{

	char *sep = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	printf(RESET);
	printf(GREEN);
	printf("\n%s\n", sep);
	printf("%s\n", sep);
	printf(RED);
	printf("%*s\n", (int)strlen(sep) / 2 + (int)strlen(str) / 2, str);
	printf(GREEN);
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
		print_split("FT_WRITE => write on stdout");
		test_ft_write();
	}
		
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_read") == 0))
	{
		print_split("FT_READ => from a file");
		test_ft_read();
	}
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcmp") == 0))
	{
		print_split("FT_STRCMP");
		test_ft_strcmp();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcpy_long") == 0))
	{
		print_split("FT_STRCPY_LONG");
		test_ft_strcpy_long();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcpy") == 0))
	{
		print_split("FT_STRCPY");
		test_ft_strcpy();
	}

	return (0);
}

