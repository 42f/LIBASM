
SRCS_DIR = ./srcs/

SRCS +=$(SRCS_DIR)main.c
SRCS +=$(SRCS_DIR)test_strlen.c
SRCS +=$(SRCS_DIR)test_read.c
SRCS +=$(SRCS_DIR)test_write.c
SRCS +=$(SRCS_DIR)test_strcmp.c
SRCS +=$(SRCS_DIR)test_strcpy.c
SRCS +=$(SRCS_DIR)test_strdup.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g

ifeq ($(DEBUG), 1)
 CFLAGS += -fsanitize=address
endif

NAME = test

LIBASM = ../libasm.a

INC_DIR = ./includes/

HEADER = $(INC_DIR)libasm.h
HEADER = $(INC_DIR)tester_libasm.h

all: $(NAME)

FORCE:
	make

$(OBJS): %.o :%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 

$(LIBASM):
	make -C ../

$(NAME): $(LIBASM) $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -L ../ -lasm -o $(NAME) 

f: test 
	./test	

ft_strlen: $(NAME) $(LIBASM) FORCE
	make -C ../
	./test $@
ft_write: $(NAME) $(LIBASM) FORCE
	./test $@
ft_read: $(NAME) $(LIBASM) FORCE
	make -C ../
	./test $@
ft_strcmp: $(NAME) $(LIBASM) FORCE
	make -C ../
	./test $@
ft_strcpy: $(NAME) $(LIBASM) FORCE
	make -C ../
	./test $@
ft_strdup: $(NAME) $(LIBASM) FORCE
	make -C ../
	./test $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test
	make fclean -C ..

re: fclean $(NAME)

.PHONY: all clean fclean re libasm objets test f main.c debug ft_strlen ft_write ft_read ft_strcmp ft_strcpy ft_strdup
