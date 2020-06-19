#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>

extern int		ft_strlen(char const *str);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dest, const char *src);
extern char		*ft_strdup(const char *s);

/*
**  BONUS PART
*/

int				ft_atoi_base(const char *str, char *base);

#endif
