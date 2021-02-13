# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberry <aberry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 03:13:54 by aberry            #+#    #+#              #
#    Updated: 2021/02/13 03:13:56 by aberry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all re clean fclean tools

NAME		=	conversion

CC			=	gcc

INC			=	-I ./includes/

ADD_FLAGS	=	-Wall -Wextra -Werror

CFLAGS		=	-O3 -MMD $(INC) $(ADD_FLAGS)

FILES		= 	$(addprefix src/,\
					conversion.c\
					$(addprefix conversion_bin/,\
							conversion_decimal_to_bin.c bin_elem.c conversion_bin.c conversion_bin_elem.c\
					)\
					$(addprefix conversion_hex/,\
							conversion_decimal_to_hex.c conversion_hex.c conversion_hex_elem.c hex_elem.c\
					)\
					$(addprefix utils/,\
							difference_addition.c utils_for_convertion.c\
					)\
				)

OBJS		=	$(FILES:.c=.o)
DEPENDS		=	$(OBJS:.o=.d)

all:		$(NAME)

$(NAME):	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS} ${DEPENDS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all

-include ${DEPENDS}
