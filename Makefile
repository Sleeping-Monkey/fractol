# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 10:37:57 by ssheba            #+#    #+#              #
#    Updated: 2019/07/18 11:09:22 by ssheba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC_DIR		=	./src
INC_DIR		=	./includes
OBJ_DIR		=	./obj
LIB_DIR		=	./libft

SRC_FILES	=	main.c set_cmpl.c mod_cmpl.c add_cmpl.c mul_cmpl.c \
				start.c hooks.c finish.c draw.c mandel.c set_img.c \
				set_point.c julia.c create_cl.c del_cl.c init_cl.c \
				reset_view.c set_color.c fractal.c
INC_FILES	=	cmpl.h fractol.h cl.h
OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
INC			=	$(addprefix $(INC_DIR)/,$(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

LIBFT		=	$(LIB_DIR)/libft.a

FLAGS		=	-Wall -Wextra -Werror -I $(LIB_DIR) -I $(INC_DIR)
FLAGS_MNLX	=	-L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -framework OpenCL
all: $(NAME)


$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(FLAGS_MNLX)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC)
	mkdir -p $(OBJ_DIR)
	gcc -c $(FLAGS) -o $@ $<

$(LIBFT): FAKE
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all


.PHONY: FAKE
