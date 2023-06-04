# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 17:19:52 by twang             #+#    #+#              #
#    Updated: 2023/05/30 19:19:29 by bpoumeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##    ~~    Colors -------------------------------------------------------------

GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
ORANGE		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
LIGHTBLUE	=	\033[36m
WHITE		=	\033[37m

##    ~~    Styles -------------------------------------------------------------

END			=	\033[0m
BOLD		=	\033[1m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m
DEL_LINE	=	\033[2K\r

##    ~~    Prints -------------------------------------------------------------

define    PRINT_CLEAN
    printf "[ ${RED}removing${END} ]\t${LIGHTBLUE}binaries files${END}\n"
endef

define    PRINT_FCLEAN
    printf "[ ${RED}removing${END} ]\t${LIGHTBLUE}executable file${END}\n\n"
endef

define    PRINT_COMPILING
    printf "%-105b%b" "[ ${PURPLE}compiling${END} ]\t${LIGHTBLUE}$<${END}" "${GREEN}[✓]${END}\n"
endef

define    PRINT_CREATING
    printf "\n[ ${PURPLE}creating${END} ]\t${LIGHTBLUE}$@${END}\n"
endef

define LINE
    printf "\n              ----------------------------\n\n"
endef
