.PHONY:		all re clean fclean tools

NAME		=	conversion

CC			=	gcc

INC			=	-I ./includes/

# ADD_FLAGS	=	-Wall -Wextra -Werror
# -Wall -Wextra -Werror

CFLAGS		=	-O3 -MMD $(INC) $(ADD_FLAGS)

FILES		= 	$(addprefix src/,\
					main.c\
					$(addprefix conversion_bin/,\
							conversion_bin.c\
					)\
					$(addprefix conversion_hex/,\
							conversion_hex.c\
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
