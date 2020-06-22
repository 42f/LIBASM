/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:56 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/22 12:48:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_STRCPY long test
////////

int test_ft_strcpy_long()
{

	char *ret_ft = NULL;
	char *ret_c = NULL;
	size_t buf_size = 1000000000;
	char *str_1 = NULL;
	char *str_2 = NULL;
	char *str_3 = NULL;
	int fd = 0;
	int ret = 0;
	size_t len_src = 0;
	size_t len_ft = 0;
	size_t len_c = 0;
	int error = 0;

	fd = open("./files/large_file.txt", O_RDONLY);
	if (fd <= 2)
	{
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return (0);
	}
	str_1 = (char *)calloc(sizeof(char), buf_size + 1);
	ret = read(fd, str_1, buf_size);
	if (ret < 0)
	{
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return (0);
	}
	close(fd);
	len_src = strlen(str_1);
	str_2 = (char*)malloc(sizeof(char) * (len_src + 1));
	str_3 = (char*)malloc(sizeof(char) * (len_src + 1));
	if (str_2 == NULL || str_3 == NULL)
	{
		printf(RED);
		printf("ERROR MALLOC");
		printf(RESET);
		return (0);
	}
	printf("FOR FT_STRCPY. Just malloced %p\n", str_2);
	printf("FOR    STRCPY. Just malloced %p\n", str_3);
	
	
	ret_ft = ft_strcpy(str_2, str_1); 
	ret_c =  strcpy(str_3, str_1);
	
	len_ft = strlen(str_2);
	len_c = strlen(str_3);
	if (ret_ft == str_2 && strncmp(ret_ft, ret_c, len_src + 1) == 0)
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
	printf(RESET);
	printf("FT_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_ft, len_ft);
	printf(DARK);
	printf(" C_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_c, len_c);
	printf("return _ft: \ndst before{%p} \ndst after (%p)\nreturn  _c: \ndst before{%p} \ndst after (%p)\n", str_2, ret_ft, str_3, ret_c);

	free(str_1);
	free(str_3);
	free(str_2);
	return (error);
}

/////////
// FT_STRCPY
// non-null argument mandatory on c function
////////

int test_ft_strcpy()
{
	int error = 0;
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
			return (0);
		printf("FOR FT_STRCPY. Just malloced %p\n", str_2[i]);
	}
	
	char *str_3[nb_test];
	for (int i = 0; i < nb_test; i++)
	{
		str_3[i] = (char*)malloc(sizeof(char) * (strlen(str_1[i]) + 1));
		if (str_3[i] == NULL)
			return (0);
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
			error++;
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
		error += test_ft_strcpy_long();

		return (error);
}

