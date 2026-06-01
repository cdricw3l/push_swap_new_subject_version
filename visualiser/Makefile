
NAME=generator
CC= cc
CFLAGS=  -g
#-Wall -Werror -Wextra
SRCS=	srcs/generateur_x_y.c \
		srcs/user_input.c \
		srcs/list_test_file.c \
		srcs/gnl/get_next_line_bonus.c \
		srcs/gnl/get_next_line_utils_bonus.c
GEN_LIST=generateur/listes/*
VAL_LOG="valgrind.log"

SRCS_OBJ= $(SRCS:.c=.o)

START_SIZE=  1
END_SIZE=	300
MIN=		-5000
MAX=		5000
RATIO=		0.5


all: $(NAME)

$(NAME): $(SRCS_OBJ)
	$(CC) $(CFLAGS)  $(SRCS_OBJ) -L../lib -lft -o $(NAME)

gen:
	node generateur/creation_file.js $(START_SIZE) $(END_SIZE) $(MIN) $(MAX) $(RATIO)

gen_clean:
	rm -rf $(GEN_LIST)/*

OS=$(shell uname)
r: $(NAME)
ifeq ( $(OS), Linux)
#@valgrind  --leak-check=full --log-file="val.log" 
	./$(NAME)
else
	@./$(NAME)
endif

TEST="13 34 4323 33 32 -1"
test:
	@../push_swap --medium $(TEST)

clean:
	rm -f $(SRCS_OBJ)  $(VAL_LOG)

fclean: clean
	rm -rf $(NAME) output

re: fclean $(NAME)

COM=generateur
git: clean
	git add .
	git commit -m $(COM)
	git push origin $(shell git branch --show-current)

.PHONY:  fclean clean all test r gen_cleangen


