#ifndef LIBASM_H
# define LIBASM_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

extern int ft_strlen(char const *str);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern int strcmp(const char *s1, const char *s2);

#endif
