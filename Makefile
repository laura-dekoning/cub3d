# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/26 12:59:37 by lade-kon      #+#    #+#                  #
#    Updated: 2025/03/27 16:56:11 by livliege      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# # LAURA's MAKEFILE!
# NAME		:=	cub3d

# CC			:=	cc -Ofast -g
# CFLAGS		:=	-Wall -Wextra 
# #-Werror -g -fsanitize=address

# LIBFT_DIR	:=	lib/libft
# LIBFT_A		:=	$(LIBFT_DIR)/libft.a
# MLX_DIR		:=	lib/MLX42
# MLX42_A		:=	$(MLX_DIR)/build/libmlx42.a
# MLX_FLAGS	:=	-ldl -lglfw -pthread -lm

# INCLS_CUB3D	:=	incl
# INCLS_LIBFT	:=	$(LIBFT_DIR)/incl
# INCLS_MLX42	:=	$(MLX_DIR)/include/MLX42
# INCLUDES	:=	-I $(INCLS_CUB3D) -I $(INCLS_LIBFT) -I $(INCLS_MLX42)

# SRC_DIR		:=	src
# SRC_FILES	:=	\
# 				string_to_rgb.c\
# 				error.c \
# 				# main.c \
# 				# free_data.c \
# 				# parse.c \
# 				# check_map.c \
# 				# safe_calloc \
# 				# get_data.c \
				
# SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

# OBJ_DIR		:=	obj
# OBJ_FILES	:=	$(SRC_FILES:.c=.o)
# OBJ			:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# .PHONY : all clean fclean re

# all: $(NAME)

# $(MLX42_A):
# 	@git submodule update --init --recursive --remote
# 	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
# 	@make -C $(MLX_DIR)/build -j4 > /dev/null

# $(LIBFT_A):
# 	@git submodule update --init --recursive --remote
# 	@make -C $(LIBFT_DIR) > /dev/null

# $(NAME) : $(OBJ) $(MLX42_A) $(LIBFT_A)
# 	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX42_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# norminette:
# 	@echo "${CYAN}🧐 Checking the Norm...${RESET}"
# 	@norminette -R CheckForbiddenSourceHeader
# 	@echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

# update:
# 	@git submodule update --init --recursive --remote
	
# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@make -C $(LIBFT_DIR) clean > /dev/null

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIBFT_DIR) fclean > /dev/null

# re: fclean all

# ## Colours ##
# RESET	:= \033[0m
# RED		:= \033[1;91m
# GREEN	:= \033[1;92m
# YELLOW	:= \033[1;93m
# BLUE	:= \033[1;94m
# PURPLE	:= \033[1;95m
# CYAN	:= \033[1;96m
# WHITE	:= \033[1;97m
# BLACK	:= \033[1;90m

#-----------------------------------------------------------------------------

# LIATH's MAKEFILE!

NAME		:=	cub3d

CC			:=	cc -Ofast -g
CFLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR	:=	lib/libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a
MLX_DIR		:=	lib/MLX42
MLX42_A		:=	$(MLX_DIR)/build/libmlx42.a
MLX_FLAGS	:=	-ldl -lglfw -pthread -lm

INCLS_CUB3D	:=	incl
INCLS_LIBFT	:=	$(LIBFT_DIR)/incl
INCLS_MLX42	:=	$(MLX_DIR)/include/MLX42
INCLUDES	:=	-I $(INCLS_CUB3D) -I $(INCLS_LIBFT) -I $(INCLS_MLX42)
HEADERS		:=	incl/liath.h

SRC_DIR		:=	src/liath_dev
SRC_FILES	:=	\
				draw_minimap.c \
				draw_player.c \
				draw_shapes.c \
				error_clear_exit.c \
				fake_parsing.c \
				festival_map.c \
				game.c \
				init_game.c \
				init_walls.c \
				keys.c \
				main_liath.c \
				minimap.c \
				player_collision.c \
				raycasting.c \
				render_3d_scene.c \
				utils.c
				
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:=	obj
OBJ_FILES	:=	$(SRC_FILES:.c=.o)
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

.PHONY : all clean fclean re

all: $(NAME)

$(MLX42_A):
	@git submodule update --init --recursive --remote
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	@make -C $(MLX_DIR)/build -j4 > /dev/null

$(LIBFT_A):
	@git submodule update --init --recursive --remote
	@make -C $(LIBFT_DIR) > /dev/null

$(NAME) : $(OBJ) $(MLX42_A) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(MLX42_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norminette:
	@echo "${CYAN}🧐 Checking the Norm...${RESET}"
	@norminette -R CheckForbiddenSourceHeader
	@echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

update:
	@git submodule update --init --recursive --remote
	
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

