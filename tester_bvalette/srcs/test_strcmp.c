/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:39 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/22 12:07:04 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_STRCMP long test
////////

int test_ft_strcmp_long()
{
	int error = 0;
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
			return (0);
		}
		str_1[i] = (char *)calloc(sizeof(char), buf_size + 1);
		ret = read(fd, str_1[i], buf_size);
		if (ret < 0)
		{
			printf(RED);
			printf("ERROR FILE TEST");
			printf(RESET);
			return (0);
		}
		close(fd);
		fd = 0;
	}

	len = strlen(str_1[1]);
	
	ret_ft = ft_strcmp(str_1[0], str_1[1]); 
	ret_c = strcmp(str_1[0], str_1[1]); 
	
	if ((ret_ft < 0 && ret_c < 0) || ret_ft == ret_c || (ret_ft > 0 && ret_c > 0))
	{
		printf(GREEN);
		printf("\n\n[✅] For very long string\n");
	}
	else
	{
		printf(RED);
		printf("\n\n[⛔️KO !] For very long string\n");
		error++;
	}
	printf(RESET);
	printf("FT_ returns %d \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", ret_ft, str_1[0], len - 10, str_1[1], len - 10);
	printf(DARK);
	printf(" C_ returns %d \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", ret_c, str_1[0], len - 10, str_1[1], len - 10);
	free(str_1[1]);
	free(str_1[0]);
	return (error);
}
/////////
// FT_STRCMP
// non-null argument mandatory on c function
////////

int test_ft_strcmp()
{
	int error = 0;
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
		if ((ret_ft < 0 && ret_c < 0) || ret_ft == ret_c || (ret_ft > 0 && ret_c > 0))
		{
			printf(GREEN);
			printf("[✅]\n\n");
		}
		else
		{
			printf(RED);
			printf("[⛔️KO !]\n\n");
			error++;
		}
		printf(RESET);
	}
	error += test_ft_strcmp_long();
	return (error);
}
