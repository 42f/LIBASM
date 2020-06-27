/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/27 15:09:09 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

void signal_catcher(int signum) 
{
	printf("Caught signal %d \n", signum);
//	g_signum++;

	exit (1);	
}

static void	print_split(char *str)
{

	char *sep = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
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
	int error = 0;
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strlen") == 0))
	{
		print_split("FT_STRLEN");
		error += test_ft_strlen();
	}
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_write") == 0))
	{
		print_split("FT_WRITE => write on stdout");
		error += test_ft_write();
	}
		
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_read") == 0))
	{
		print_split("FT_READ => from a file");
		error += test_ft_read();
	}
	
	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcmp") == 0))
	{
		print_split("FT_STRCMP");
		error += test_ft_strcmp();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcpy_long") == 0))
	{
		print_split("FT_STRCPY_LONG");
		error += test_ft_strcpy_long();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strcpy") == 0))
	{
		print_split("FT_STRCPY");
		error += test_ft_strcpy();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strdup") == 0))
	{
		print_split("FT_STRDUP");
		error += test_ft_strdup();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_strdup_long") == 0))
	{
		print_split("FT_STRDUP_LONG");
		error += test_ft_strdup_long();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_atoi_base") == 0))
	{
		print_split("FT_ATOI_BASE");
		error += test_ft_atoi_base();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_list_push_front") == 0))
	{
		print_split("FT_LIST_PUSH_FRONT");
		error += test_ft_list_push_front();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_list_remove_if") == 0))
	{
		print_split("FT_LIST_REMOVE_IF");
		error += test_ft_list_remove_if();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_list_size") == 0))
	{
		print_split("FT_LIST_SIZE");
		error += test_ft_list_size();
	}

	if (ac == 1 || (ac == 2 && strcmp(av[1], "ft_list_sort") == 0))
	{
		print_split("FT_LIST_SORT");
		error += test_ft_list_sort();
	}

	print_split("TESTS RESULT");
	if (error == 0)
	{
		printf(GREEN);
		printf("\t\t\tFINAL : [PASSED] ✅\n");
		printf("\t\t\t[%d] errors\n\n\n", error);
	}
	else
	{
		printf(RED);
		printf("\t\t\tFINAL : [FAILED] ⛔️\a");
		printf("\t\t\t[%d] errors\n\n\n", error);
		error++;
	}
	
	return (0);
}

