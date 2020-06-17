/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:36:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 16:47:45 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_STRCMP long test
////////

void test_ft_strdup_long()
{

	char *ret_ft = NULL;
	char *ret_c = NULL;
	size_t buf_size = 10000000;
	char *str_1 = NULL;
	int fd = 0;
	int ret = 0;
	size_t len_src = 0;
	size_t len_ft = 0;
	size_t len_c = 0;

	fd = open("./files/large_file.txt", O_RDONLY);
	if (fd <= 2)
	{
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return ;
	}
	str_1 = (char *)calloc(sizeof(char),(buf_size + 1));
	if (str_1 == NULL)
	{
		printf(RED);
		printf("ERROR CALLOC");
		printf(RESET);
		return ;
	}
	ret = read(fd, str_1, buf_size);
	if (ret < 0)
	{
		free(str_1);	
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return ;
	}
	close(fd);
		
	ret_ft = ft_strdup(str_1); 
	if (ret_ft == NULL)
	{
		printf(RED);
		printf("\n\n[⛔️KO !]  => LIBFT FUNCTION Returned NULL pointer");
		free(ret_c);
		return ;
	}
	ret_c =  strdup(str_1);
	if (ret_c == NULL)
	{
		printf(RED);
		printf("\n\n[⛔️KO !]  => LIBC FUNCTION Returned NULL pointer");
		return ;
	}
	len_src = strlen(str_1);
	len_ft = strlen(ret_ft);
	len_c = strlen(ret_c);
	if (strcmp(ret_ft, ret_c) == 0)
	{
		printf(GREEN);
		printf("\n\n[✅] For very long string\n");
	}
	else
	{
		printf(RED);
		printf("\n\n[%d][⛔️KO !] For very long string\n",	strcmp(ret_ft, ret_c));
	}
	printf(RESET);
	printf("FT_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_ft, len_ft);
	printf(DARK);
	printf(" C_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_c, len_c);
	printf("return _ft: \nsrc {%p} \ndst (%p)\nreturn  _c: \nsrc{%p} \ndst (%p)\n", str_1, ret_ft, str_1, ret_c);

	free(str_1);
	free(ret_c);
	free(ret_ft);
}


/////////
/// FT_STRCMP long test
////////

void test_ft_strdup()
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

	for (int i = 0; i < nb_test; i++)
	{
		ret_c =  strdup(str_1[i]);
		if (ret_c == NULL)
		{
			printf(RED);
			printf("\n\n[⛔️KO !]  => LIBC FUNCTION Returned NULL pointer");
			return ;
		}
		ret_ft = ft_strdup(str_1[i]); 
		if (ret_ft == NULL)
		{
			printf(RED);
			printf("\n\n[⛔️KO !]  => LIBFT FUNCTION Returned NULL pointer");
			free(ret_c);
			return ;
		}

		if (strcmp(ret_ft, str_1[i]) == 0)
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
	printf("return _ft: \nsrc {%p} \ndst (%p)\nreturn  _c: \nsrc{%p} \ndst (%p)\n", str_1, ret_ft, str_1, ret_c);
	
		free (ret_c);
		free (ret_ft);
	}
	printf(RESET);
	test_ft_strdup_long();
}
