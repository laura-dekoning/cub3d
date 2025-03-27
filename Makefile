# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/26 12:59:37 by lade-kon      #+#    #+#                  #
#    Updated: 2025/03/27 07:55:52 by lade-kon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d

CC			:=	cc -Ofast -g
CFLAGS		:=	-Wall -Werror -Wextra -g -fsanitize=address

LIBFT_DIR	:=	lib/libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a
MLX_DIR		:=	lib/MLX42
MLX42_A		:=	$(MLX_DIR)/build/libmlx42.a
MLX_FLAGS	:=	-ldl -lglfw -pthread -lm

INCLS_CUB3D	:=	incl
INCLS_LIBFT	:=	$(LIBFT_DIR)/incl
INCLS_MLX42	:=	$(MLX_DIR)/include/MLX42
INCLUDES	:=	-I $(INCLS_CUB3D) -I $(INCLS_LIBFT) -I $(INCLS_MLX42)

SRC_DIR		:=	src
SRC_PRINT	:=	printing
SRC_FILES	:=	alloc_mem_for_data.c \
				error.c \
				fill_map.c \
				free_data.c \
				get_data.c \
				main.c \
				is_map_content.c \
				is_setting.c \
				parse_validate_init_map.c \
				parse_validate_init_rgb.c \
				parse_validate_init_textures.c \
				read_file.c \
				safe_calloc.c \
				set_default.c \
				string_to_rgb.c \
				validate_file_and_init_data.c \
				validate_map.c \
				$(addprefix $(SRC_PRINT)/, \
				print_adjacent.c \
				print_array_with_values.c \
				print_check.c \
				print_data.c \
				print_floor_and_ceiling.c \
				print_map.c \
				print_player.c \
				print_string_with_values.c ) \
				
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:=	obj
OBJ_FILES	:=	$(SRC_FILES:.c=.o)
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

.PHONY : all clean fclean re

all: $(NAME)

$(MLX42_A):
	git submodule update --init --recursive --remote
	cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	make -C $(MLX_DIR)/build -j4 > /dev/null

$(LIBFT_A):
	git submodule update --init --recursive --remote
	make -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJ_DIR) $(OBJ) $(MLX42_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX42_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_PRINT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norminette:
	echo "${CYAN}🧐 Checking the Norm...${RESET}"
	norminette -R CheckForbiddenSourceHeader
	echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

update:
	git submodule update --init --recursive --remote
	
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

## Colours ##
RESET	:= \033[0m
RED		:= \033[1;91m
GREEN	:= \033[1;92m
YELLOW	:= \033[1;93m
BLUE	:= \033[1;94m
PURPLE	:= \033[1;95m
CYAN	:= \033[1;96m
WHITE	:= \033[1;97m
BLACK	:= \033[1;90m