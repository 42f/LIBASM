/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:18 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 13:37:29 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_WRITE
////////

void test_ft_write()
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
