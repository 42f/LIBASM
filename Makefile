
SRCS_DIR = ./srcs/

SRCS +=$(SRCS_DIR)ft_strlen.s
SRCS +=$(SRCS_DIR)ft_read.s
SRCS +=$(SRCS_DIR)ft_write.s
SRCS +=$(SRCS_DIR)ft_strcmp.s
SRCS +=$(SRCS_DIR)ft_strcpy.s
#SRCS +=$(SRCS_DIR)ft_strdup.s
#SRCS +=$(SRCS_DIR)ft_strlen.s

OBJS = $(SRCS:.s=.o)

NA = nasm

OS := $(shell uname -s)

ifeq ($(OS), Linux)
 NFLAGS = -f elf64
else
 NFLAGS = -f machof64
endif
NFLAGS += -g
NFLAGS += -F dwarf

CC = clang

CFLAGS = -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -fsanitize=address

NAME = libasm.a

INC_DIR = ./includes/

HEADER = $(INC_DIR)libasm.h

all :		$(NAME)

$(NAME):	$(OBJS)
	@echo "\n		🔗 Linking $@'s objects files...\n"
	ar rcs $@ $^
	@echo "\n		🥳  Yay  !  $@ done.\n"

$(OBJS):	%.o: %.s $(HEADER)
	$(NA) -I $(INC_DIR) $(NFLAGS) $< 

test: $(NAME) $(HEADER) main.c
	$(CC) $(CFLAGS) -I $(INC_DIR) main.c -lft -L. -lasm -o test

f: test 
	./test	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test

re: fclean $(NAME)

.PHONY: all clean fclean re libasm objets test f main.c
