include print_libft.mk

.SILENT:

NAME	=	libft.a

CC	=	cc

CFLAGS	=	-g3 -Werror -Wall -Wextra

AR	= 	ar

ARFLAGS =	rcs

SANITY	=	-fsanitize=address

FILES	=	ft_atoi.c 				\
			ft_memdup.c 			\
			ft_bzero.c 				\
			ft_calloc.c 			\
			ft_is_overflowing.c 	\
			ft_isalnum.c 			\
			ft_isalpha.c 			\
			ft_isascii.c 			\
			ft_isdigit.c 			\
			ft_isprint.c 			\
			ft_itoa.c 				\
			ft_memchr.c 			\
			ft_memcmp.c 			\
			ft_memcpy.c 			\
			ft_memdup.c 			\
			ft_memmove.c 			\
			ft_memset.c 			\
			ft_putchar_fd.c 		\
			ft_putendl_fd.c 		\
			ft_putnbr_fd.c 			\
			ft_putstr_fd.c 			\
			ft_split.c 				\
			ft_split_charset.c 		\
			ft_strchr.c 			\
			ft_strdup.c 			\
			ft_striteri.c 			\
			ft_strjoin.c 			\
			ft_strlcat.c 			\
			ft_strlcpy.c 			\
			ft_strlen.c 			\
			ft_strmapi.c 			\
			ft_strncmp.c 			\
			ft_strnstr.c 			\
			ft_strstr.c				\
			ft_strrchr.c 			\
			ft_strtrim.c 			\
			ft_substr.c 			\
			ft_swap.c 				\
			ft_tolower.c 			\
			ft_issign.c 			\
			ft_toupper.c 			\
			ft_strjoin_three.c 		\
			ft_intarr_set.c 		\
			is_from_charset.c 		\
			str_is_made_of.c 		\
			ft_ustrdup.c 			\
			ft_ustrlen.c 			\
			ft_strcmp.c 			\
			put_ert.c 				\
			maths.c 				\
			ft_atoi_on.c 			\
			ft_strcpy.c 			\
			int_arr_utils.c 		\
			ft_swap.c 				\
			list_utils.c 			\
			per_n_ret.c 			\
			ft_lststr_to_str.c 		\
			ft_print_split.c 		\
			close_pipe_arr.c 		\
			ft_free_int_arr.c 		\
			ft_join_str_arr_on.c 	\
			ft_get_env.c 			\
			ft_str_arr.c			\
			open_file.c				\
			ft_strnstr.c			\
			ft_free.c				\
			ft_strjoin_paths.c		\
			ft_printf.c				\
			check_extension.c		\
			open_file.c				\
			ft_putnbr_base_fd.c		\
			ft_putnbr_unsigned_fd.c	\
			_get_next_line.c		\
			lstc.c					\
			lstc_2.c				\
			ft_sort_arr.c

HFILES	=	libft.h

ODIR	=	./

HDIR	=	.

SRCS	=	$(FILES)

OBJS	=	$(addprefix $(ODIR), $(FILES:.c=.o))

BOBJS	=	$(addprefix $(ODIR), $(BFILES:.c=.o))

all	:	 $(ODIR) $(NAME)

$(NAME)	:	$(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(PRINT_CREATING)

$(ODIR)	:
	mkdir $(ODIR)

$(ODIR)%.o	:	%.c $(HFILES)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<
	$(PRINT_COMPILING)

clean	:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)
	$(PRINT_CLEAN)

fclean	:	clean
	rm -rf $(NAME)
	$(PRINT_FCLEAN)

re	:	
	make fclean
	make all

bonus	:	$(BOBJS) $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BOBJS)

ncpy	:	$(NAME)
	cp $(NAME) ~/lib/
	cp $(HFILES) ~/lib/

clearm	:
	clear
	make

comptest	:
	make
	make fclean

.PHONY	:	all clean fclean re ncpy bonus

