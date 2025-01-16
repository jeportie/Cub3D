# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 21:02:39 by jeportie          #+#    #+#              #
#    Updated: 2024/10/25 14:21:13 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

### BEGIN AUTO GENERATED FILES ###
# List of source files:
SRC = \
  src/memory/ft_bzero.c \
  src/memory/ft_memset.c \
  src/memory/ft_calloc.c \
  src/memory/ft_memchr.c \
  src/memory/ft_memcmp.c \
  src/memory/ft_memcpy.c \
  src/memory/ft_memmove.c \
  src/memory/ft_realloc.c \
  src/memory/ft_memswap.c \
  src/string/ft_split.c \
  src/string/ft_strchr.c \
  src/string/ft_strdup.c \
  src/string/ft_striteri.c \
  src/string/ft_strjoin.c \
  src/string/ft_strlcpy.c \
  src/string/ft_strlen.c \
  src/string/ft_strmapi.c \
  src/string/ft_strncmp.c \
  src/string/ft_strnstr.c \
  src/string/ft_strrchr.c \
  src/string/ft_strtrim.c \
  src/string/ft_substr.c \
  src/string/ft_strlcat.c \
  src/string/ft_strcat.c \
  src/string/ft_strcspn.c \
  src/string/ft_strexpand.c \
  src/string/ft_strndup.c \
  src/string/ft_strpbrk.c \
  src/string/ft_strreplace.c \
  src/string/ft_strtok.c \
  src/conversion/ft_atol.c \
  src/conversion/ft_itoa.c \
  src/conversion/ft_tolower.c \
  src/conversion/ft_toupper.c \
  src/conversion/ft_ulltoa_base.c \
  src/conversion/ft_utoa_base.c \
  src/conversion/ft_atoi.c \
  src/conversion/ft_ftoa.c \
  src/conversion/ft_htoa.c \
  src/conversion/ft_itobase.c \
  src/conversion/ft_strtoi.c \
  src/io/ft_putchar_fd.c \
  src/io/ft_putendl_fd.c \
  src/io/ft_putnbr_fd.c \
  src/io/ft_putstr_fd.c \
  src/io/ft_read_file.c \
  src/io/ft_write_str.c \
  src/printf/ft_perror.c \
  src/printf/ft_buffer_add.c \
  src/printf/ft_handle_hash_flag.c \
  src/printf/ft_handle_space_flag.c \
  src/printf/ft_apply_precision.c \
  src/printf/ft_handle_string.c \
  src/printf/ft_handle_binary.c \
  src/printf/ft_handle_float.c \
  src/printf/ft_parse_precision.c \
  src/printf/ft_handle_hexadecimal.c \
  src/printf/ft_handle_int.c \
  src/printf/ft_handle_pointer.c \
  src/printf/ft_isconvert_spec.c \
  src/printf/ft_isflag.c \
  src/printf/ft_nbr_len.c \
  src/printf/ft_parse_flags.c \
  src/printf/ft_parse_format.c \
  src/printf/ft_snprintf.c \
  src/printf/ft_printf.c \
  src/printf/ft_apply_width.c \
  src/printf/ft_buffer_flush.c \
  src/printf/ft_check_format.c \
  src/printf/ft_handle_char.c \
  src/printf/ft_dprintf.c \
  src/printf/ft_handle_plus_flag.c \
  src/bool/ft_isalpha.c \
  src/bool/ft_isprint.c \
  src/bool/ft_isspace.c \
  src/bool/ft_isalnum.c \
  src/bool/ft_isdigit.c \
  src/bool/ft_isascii.c \
  src/bool/ft_isxdigit.c \
  src/utils/ft_getenv.c \
  src/utils/ft_check_fd.c \
  src/utils/ft_check_malloc.c \
  src/utils/ft_check_pid.c \
  src/utils/ft_find_cmd_path.c \
  src/utils/ft_get_home_dir.c \
  src/utils/ft_issorted.c \
  src/utils/ft_path_join.c \
  src/utils/ft_strarr_free.c \
  src/utils/ft_strarr_len.c \
  src/get_next_line/get_next_line.c 
### END AUTO GENERATED FILES ###

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
