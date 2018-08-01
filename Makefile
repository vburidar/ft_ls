NAME = ft_ls

SRC = main.c\
	  ft_create_lst.c\
	  ft_print_directory.c\
	  ft_strcmp.c\
	  ft_inittabdir.c\
	  ft_get_flag.c\
	  ft_get_l.c\
	  ft_rights.c\
	  ft_sort_lst.c\
	  ft_printl.c\
	  ft_print_lst.c\
	  ft_free_elem.c\
	  ft_sort_time.c\
	  ft_time_calc.c\
	  ft_swap_lst.c\
	  ft_max_len.c\
	  ft_init_link.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L. ft_printf/libftprintf.a

$(FT_PRINTF):
	make all -C ft_printf

%.o : %.c
	gcc -o $@ -c $< -Wall -Wextra -Werror

clean :
	rm -rf *.o
	make clean -C ft_printf

fclean : clean 
	rm -rf $(NAME)
	make fclean -C ft_printf

re :	
	make fclean
	make
