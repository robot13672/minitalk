# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:53:41 by ikhristi          #+#    #+#              #
#    Updated: 2023/02/24 18:07:05 by ikhristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c

SRC_CLIENT = client.c

SERVER = server
CLIENT = client

LIBFT = inc/libft/
PRINTF = inc/printf/

SRCS_DIR = ./
OBJS_DIR = objs/

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_SERVER))
OBJ_CLIENT_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_CLIENT))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/server.h inc/client.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(SERVER): $(OBJ_SERVER_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(SERVER) $(OBJ_SERVER_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a

$(CLIENT): $(OBJ_CLIENT_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(CLIENT) $(OBJ_CLIENT_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a

bonus: all

clean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(CLIENT)
	@rm -f $(SERVER)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)


fclean: clean
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

re: fclean all