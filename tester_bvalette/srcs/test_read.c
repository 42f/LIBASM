/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:46 by bvalette          #+#    #+#             */
/*   Updated: 2020/06/17 13:36:51 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "tester_libasm.h"

/////////
// FT_READ
////////

void test_ft_read()
{
	unsigned int fd = open("./files/alpha.txt", O_RDONLY);
	int buf_size = 2048;
	char buf[buf_size];

	ft_read(fd, &buf, buf_size);
	printf("%s", buf);
}

