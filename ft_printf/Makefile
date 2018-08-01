NAME	= libftprintf.a
SRC		= ft_atoi.c\
		  ft_bzero.c\
		  ft_char_str.c\
		  ft_concat.c\
		  ft_fill_buff.c\
		  ft_filltab.c\
		  ft_getwchar.c\
		  ft_isdigit.c\
		  ft_itoa_base.c\
		  ft_modif_len.c\
		  ft_plus_space.c\
		  ft_precision.c\
		  ft_printf.c\
		  ft_putchar.c\
		  ft_secure_strsub.c\
		  ft_signed_nb_pt.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strcpy.c\
		  ft_strdup.c\
		  ft_strjoin.c\
		  ft_strlen.c\
		  ft_strsub.c\
		  ft_tools.c\
		  ft_unsigned_nb.c\

			
OBJ		= $(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	: $(OBJ)
	ar -r $@ $^

%.o: %.c
	gcc -o $@ -c $< -Wall -Wextra -Werror

clean	:
	rm -rf *.o

fclean	: clean
	rm -rf $(NAME)

re		: fclean all
