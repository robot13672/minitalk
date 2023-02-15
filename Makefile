# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:53:41 by ikhristi          #+#    #+#              #
#    Updated: 2023/02/14 15:59:38 by ikhristi         ###   ########.fr        #
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
OBJ_SERVER_PREFIX = $(addprefix $(OBJS_DIR), $(OBJ_SERVER))