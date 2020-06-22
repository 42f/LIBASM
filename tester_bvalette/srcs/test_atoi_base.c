/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/22 11:46:48 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
/// FT_atoi_base
////////

int test_ft_atoi_base()
{
	int ret = 0;
	int error = 0;

//  [expected return], [ft_atoi_base str arg], [ft_atoi_base base arg]
	char *test[] = 
	{
		"1346", "542", "0123456789ABCDEF",
		"66", "42", "0123456789ABCDEF",
		"1346", " 542", "0123456789ABCDEF",
		"1346", "      542 ", "0123456789ABCDEF",
		"1346", " +542", "0123456789ABCDEF",
		"1346", "+542", "0123456789ABCDEF",
		"42", "   +2A   e3", "0123456789ABCDEF",
		"1", "   1", "0123456789ABCDEF",
		"1", "   -1", "0123456789ABCDEF",
		"5", " xyz", "xyz",
		"66", "	42", "0123456789ABCDEF",
		
		"0", "x", "",
		"0", "x", " ",
		"0", "x", "x",
		"0", "xxx", "xxyz",
		"0", "xxx", "xyzx",
		"0", "xxx", "xyz-",
		"0", "xxx", "x+yz",
		"0", "xxx", "x yz",
		"0", "0", "0123456789ABCDEF",
		"15", "F", "0123456789ABCDEF",
		"0", "", "0123456789ABCDEF",
		"0", NULL, "0123456789ABCDEF",
		"0", "42", NULL
	};
	
	int nb_test = sizeof (test) / 8 / 3;
	int expected_ret = 0;

	for (int i = 0; i < nb_test * 3; i += 3)
	{
		expected_ret =  atoi(test[i]);
		ret =  ft_atoi_base(test[i + 1], test[i + 2]);
		printf(DARK"Test #%2d : [%-14s] BASE [%16s]"RESET, i / 3, test[i + 1], test[i + 2]);
		if (expected_ret == ret)
		{
			if (*test[i] != '0')
				printf(GREEN);
			else
				printf(DARK);
			printf("expecting [%5d] return = %5d --> ", expected_ret, ret);
			printf("[✅]\n");
		}
		else
		{
			printf(RED);
			printf("expecting [%5d] return = %5d --> ", expected_ret, ret);
			printf("[⛔️KO !]\n");
			error++;
		}
		printf(RESET);
	}
	return (error);
}

