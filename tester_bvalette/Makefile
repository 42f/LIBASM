
SRCS_DIR = ./srcs/

SRCS +=$(SRCS_DIR)main.c
SRCS +=$(SRCS_DIR)test_strlen.c
SRCS +=$(SRCS_DIR)test_read.c
SRCS +=$(SRCS_DIR)test_write.c
SRCS +=$(SRCS_DIR)test_strcmp.c
SRCS +=$(SRCS_DIR)test_strcpy.c
SRCS +=$(SRCS_DIR)test_strdup.c
SRCS +=$(SRCS_DIR)test_atoi_base.c
SRCS +=$(SRCS_DIR)test_list_push_front.c
SRCS +=$(SRCS_DIR)test_list_remove_if.c
SRCS +=$(SRCS_DIR)test_list_size.c
SRCS +=$(SRCS_DIR)test_ft_itoa.c
SRCS +=$(SRCS_DIR)test_list_sort.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g
#CFLAGS += -fsanitize=address

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
	make bonus -C ../

$(OBJS): %.o :%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 

$(LIBASM):
	make bonus -C ../

$(NAME): $(LIBASM) $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -L ../ -lasm -o $(NAME) 

f: FORCE $(NAME) 
	./test	

ft_atoi_base: FORCE $(NAME)
	./test $@
ft_strlen: FORCE $(NAME)
	./test $@
ft_write: FORCE $(NAME)
	./test $@
ft_read: FORCE $(NAME)
	./test $@
ft_strcmp: FORCE $(NAME)
	./test $@
ft_strcpy: FORCE $(NAME)
	./test $@
ft_strdup: FORCE $(NAME)
	./test $@
ft_list_push_front: FORCE $(NAME)
	./test $@
ft_list_remove_if: FORCE $(NAME)
	./test $@
ft_list_size: FORCE $(NAME)
	./test $@
ft_list_sort: FORCE $(NAME)
	./test $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test
	make fclean -C ..

re: fclean $(NAME)

.PHONY: all clean fclean re libasm objets test f main.c debug ft_strlen ft_write ft_read ft_strcmp ft_strcpy ft_strdup
