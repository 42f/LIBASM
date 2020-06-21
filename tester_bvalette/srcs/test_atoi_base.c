/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/21 13:12:12 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_atoi_base
////////

void test_ft_atoi_base()
{
	char *test[] = 
	{
		"0", "x", "",
		"0", "x", " ",
		"0", "x", "x",
		"0", "xxx", "xxyz",
		"0", "xxx", "xyzx",
		"0", "xxx", "xyz-",
		"0", "xxx", "x+yz",
		"0", "xxx", "x yz",
		"0", "", "0123456789ABCDEF",

		"4242", "   +2A2A e3", "0123456789ABCDEF",
		"1", "   1", "0123456789ABCDEF",
		"1", "   -1", "0123456789ABCDEF",
		"1", " xyz", "xyz",
		"1", "	42", "0123456789ABCDEF",

		"1", "42", "0123456789ABCDEF"
	};
	
	int nb_test = sizeof (test) / 8 / 3;
	int ret = 0;
	int expected_ret = 0;

	for (int i = 0; i < nb_test * 3; i += 3)
	{
		expected_ret =  atoi(test[i]);
		ret =  ft_atoi_base(test[i + 1], test[i + 2]);
		printf(DARK"Test #%2d : [%14s] BASE [%16s]"RESET, i / 3, test[i + 1], test[i + 2]);
		if (expected_ret == ret)
		{
			printf(GREEN);
			printf("expecting [%2d] return = %2d --> ", expected_ret, ret);
			printf("[✅]\n");
		}
		else
		{
			printf(RED);
			printf("expecting [%2d] return = %2d --> ", expected_ret, ret);
			printf("[⛔️KO !]\n");
		}
		printf(RESET);
	}
}

