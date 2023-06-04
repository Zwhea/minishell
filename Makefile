# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:09:46 by twang             #+#    #+#              #
#    Updated: 2023/06/02 14:49:19 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/print.mk
include config/sources.mk
include config/headers.mk

.SILENT:

#--variables-------------------------------------------------------------------#

NAME		=	minishell
DEBUG		=	no
VALGRIND	=	no

BPOUMEAU	=	\e]8;;https://profile.intra.42.fr/users/bpoumeau\a\e[34mbpoumeau\e[34m\e]8;;\a
TWANG		=	\e]8;;https://profile.intra.42.fr/users/twang\a\e[34mtwang\e[34m\e]8;;\a

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	incs
LIBFT_DIR	=	libft

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	sources
OBJ_DIR		=	.objs

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-g3 -Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(INC_DIR)

#--debug flags--------------------------------------------------------#

DFLAGS		=	-g3 -fsanitize=address

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--leaks flags--------------------------------------------------------#

LEAKS	=	valgrind --suppressions=ignore_rl_reachable.txt --leak-check=full --track-fds=yes

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) header
	$(MAKE) -C ./libft
	$(MAKE) $(NAME) -j

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $^ $(CFLAGS) $(LIBFT) -o $@ -lreadline
	$(PRINT_CREATING)

$(OBJ_DIR)/%.o: %.c $(HEADERS) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(PRINT_COMPILING)

#--libs, debugs & bonus--------------------------------------------------------#

lib:
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) re -j DEBUG=yes

leaks:
	clear
	$(MAKE) -j VALGRIND=yes
	$(LEAKS) ./minishell

leak_all:    all
	echo "{" > valgrind_ignore_leaks.txt
	echo "leak readline" >> valgrind_ignore_leaks.txt
	echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
	echo "    ..." >> valgrind_ignore_leaks.txt
	echo "    fun:readline" >> valgrind_ignore_leaks.txt
	echo "}" >> valgrind_ignore_leaks.txt
	echo "{" >> valgrind_ignore_leaks.txt
	echo "    leak add_history" >> valgrind_ignore_leaks.txt
	echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
	echo "    ..." >> valgrind_ignore_leaks.txt
	echo "    fun:add_history" >> valgrind_ignore_leaks.txt
	echo "}" >> valgrind_ignore_leaks.txt
	   valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full \
	            --show-leak-kinds=all --track-fds=yes \
	            --show-mismatched-frees=yes --read-var-info=yes \
	            --log-file=valgrind.txt ./${NAME}

#--print header----------------------------------------------------------------#

header:
	printf "\n${PURPLE}project:\t${END}${BLUE}minishell${END}\n"
	printf "${PURPLE}author:\t\t${END}${BLUE}${BPOUMEAU} && ${TWANG}${END}\n"
	printf "${PURPLE}leaks mode:\t${END}${BLUE}${VALGRIND}${END}\n"
	printf "${PURPLE}debug mode:\t${END}${BLUE}${DEBUG}${END}\n"
	printf "${PURPLE}compiler:\t${END}${BLUE}${CC}${END}\n"
	printf "${PURPLE}flags:\t\t${END}${BLUE}${CFLAGS}${END}\n"
	printf "${PURPLE}date:\t\t${END}${BLUE}2023/03/20${END}\n"
	printf "              ____________________________\n\n"

#--re, clean & fclean----------------------------------------------------------#

re:
	clear
	$(MAKE) fclean
	$(MAKE) -j all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJECTS)
	$(PRINT_CLEAN)

fclean:
	clear
	$(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(PRINT_FCLEAN)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all lib debug re clean fclean
