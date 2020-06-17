/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:01:02 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 13:15:03 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

static void	print_split(char *str)
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

