/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:36:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/27 15:30:23 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_STRCMP long test
////////

int test_ft_strdup_long()
{
	int error = 0;
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
		return (0);
	}
	str_1 = (char *)calloc(sizeof(char),(buf_size + 1));
	if (str_1 == NULL)
	{
		printf(RED);
		printf("ERROR CALLOC");
		printf(RESET);
		return (0);
	}
	ret = read(fd, str_1, buf_size);
	if (ret < 0)
	{
		free(str_1);	
		printf(RED);
		printf("ERROR FILE TEST");
		printf(RESET);
		return (0);
	}
	close(fd);
		
	ret_ft = ft_strdup(str_1); 
	if (ret_ft == NULL)
	{
		if (errno == 12)
		{
			// code to make malloc fail in the asm code
			//mov r12, 100000
			//mul r12
			printf(GREEN);
			printf("\n\n MALLOC FAILED : LIBFT FUNCTION Returned NULL pointer, errno was set to : %d", errno );
		}
		else
		{
			printf(RED);
			printf("\n\n LIBFT FUNCTION Returned NULL pointer, but errno was set to : %d", errno );
			error++;
		}
		free(ret_c);
		return (error);
	}
	ret_c =  strdup(str_1);
	if (ret_c == NULL)
	{
		printf(RED);
		printf("\n\n[⛔️KO !]  => LIBC FUNCTION Returned NULL pointer");
		error++;
		return (error);
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
		error++;
	}
	printf(RESET);
	printf("FT_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_ft, len_ft);
	printf(DARK);
	printf(" C_ \n  src[%.10s] .... (+ %zu char)\n=>dst[%.10s] .... (+ %zu char)\n", str_1, len_src, ret_c, len_c);
	printf("return _ft: \nsrc {%p} \ndst (%p)\nreturn  _c: \nsrc{%p} \ndst (%p)\n", str_1, ret_ft, str_1, ret_c);

	free(str_1);
	free(ret_c);
	free(ret_ft);
	return (error);
}


/////////
/// FT_STRCMP long test
////////

int test_ft_strdup()
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

	for (int i = 0; i < nb_test; i++)
	{
		ret_c =  strdup(str_1[i]);
		if (ret_c == NULL)
		{
			printf(RED);
			printf("\n\n[⛔️KO !]  => LIBC FUNCTION Returned NULL pointer");
			return (0);
		}
		ret_ft = ft_strdup(str_1[i]); 
		if (ret_ft == NULL)
		{
			printf(RED);
			printf("\n\n[⛔️KO !]  => LIBFT FUNCTION Returned NULL pointer");
			free(ret_c);
			return (0);
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
			error++;
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
	error += test_ft_strdup_long();
	return (error);
}
