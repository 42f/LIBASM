/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:11 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 13:43:23 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_STRLEN
////////

void test_ft_strlen()
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
		printf("[%s]\nlen = %d | %d --> ", str[i], ret_ft, ret_c);
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
