
SRCS_DIR = ./srcs/

SRCS +=$(SRCS_DIR)ft_strlen.s
SRCS +=$(SRCS_DIR)ft_read.s
SRCS +=$(SRCS_DIR)ft_write.s
SRCS +=$(SRCS_DIR)ft_strcmp.s
SRCS +=$(SRCS_DIR)ft_strcpy.s
SRCS +=$(SRCS_DIR)ft_strdup.s

OBJS = $(SRCS:.s=.o)

SRCS_BONUS += $(SRCS_DIR)ft_atoi_base.s
SRCS_BONUS += $(SRCS_DIR)ft_atoi_base_utils.s
SRCS_BONUS += $(SRCS_DIR)ft_atoi_base_skip.s

OBJS_BONUS = $(SRCS_BONUS:.s=.o)

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
#CFLAGS += -fsanitize=address

NAME = libasm.a

INC_DIR = ./includes/

HEADER = $(INC_DIR)libasm.h

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "\n		🔗 Linking $@'s objects files...\n"
	ar rcs $(NAME) $^
	@echo "\n		🥳  Yay  !  $@ done.\n"

$(NAME):	$(OBJS)
	@echo "\n		🔗 Linking $@'s objects files...\n"
	ar rcs $@ $^
	@echo "\n		🥳  Yay  !  $@ done.\n"

$(OBJS):	%.o: %.s $(HEADER)
	$(NA) -I $(INC_DIR) $(NFLAGS) $< 

$(OBJS_BONUS):	%.o: %.s $(HEADER) 
	$(NA) -I $(INC_DIR) $(NFLAGS) $< 

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean $(NAME)

re_bonus: fclean bonus

.PHONY: all clean fclean re libasm objets test f main.c
