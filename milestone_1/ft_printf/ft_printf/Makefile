# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 18:41:17 by prasingh          #+#    #+#              #
#    Updated: 2025/12/07 20:51:57 by prasingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = libftprintf.a
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src
SRC         = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/parse_flags.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/utoa_helpers.c \
		$(SRC_DIR)/char_helpers.c \
		$(SRC_DIR)/string_helpers.c \
		$(SRC_DIR)/convert_chars.c \
		$(SRC_DIR)/number_helpers.c \
		$(SRC_DIR)/convert_int.c \
		$(SRC_DIR)/convert_unsigned.c \
		$(SRC_DIR)/hex_calculations.c \
		$(SRC_DIR)/hex_formatting.c \
		$(SRC_DIR)/convert_hex.c \
		$(SRC_DIR)/convert_pointer.c \
		$(SRC_DIR)/pointer_helpers.c
OBJ         = $(SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I include -I $(LIBFT_DIR)
AR          = ar
ARFLAGS     = rcs
RM          = rm -f
CHANGE_DIRECTORY_FLAG = -C

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) $(CHANGE_DIRECTORY_FLAG) $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)
	$(MAKE) $(CHANGE_DIRECTORY_FLAG) $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(CHANGE_DIRECTORY_FLAG) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
