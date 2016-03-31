NAME = ft_printf

SRC_NAME = my_printf.c \
			flags.c \
			convert.c \
			variable_check.c \
			variable_check1.c \
			variable_def.c \
			lenght.c \
			print_memory.c \
			display.c

INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
LIB_NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix -I,$(INC_PATH))

all:$(NAME)

$(NAME): $(OBJ) libf
	$(CC) $(OBJ) $(LIB) $(INC) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

libf:
	make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_PATH) fclean
	@mkdir -p $(OBJ_PATH)


re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
