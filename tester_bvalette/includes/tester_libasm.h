#ifndef TESTER_LIBASM_H
# define TESTER_LIBASM_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define DARK "\033[1;93m"
# define RESET "\033[0m"

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>


int	test_ft_strlen();
int	test_ft_write();
int	test_ft_read();
int	test_ft_strcmp();
int	test_ft_strcmp_long();
int	test_ft_strcpy();
int	test_ft_strcpy_long();
int	test_ft_strdup();
int	test_ft_strdup_long();
int	test_ft_atoi_base();
int	test_ft_list_push_front();
int	test_ft_list_remove_if();
/*
int	test_ft_list_size();
int	test_ft_list_sort();
*/
#endif
