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


void	test_ft_strlen();
void	test_ft_write();
void	test_ft_read();
void	test_ft_strcmp();
void	test_ft_strcmp_long();
void	test_ft_strcpy();
void	test_ft_strcpy_long();
void	test_ft_strdup();
void	test_ft_strdup_long();

#endif
