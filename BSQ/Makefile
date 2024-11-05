SRC = \
		src/main.c\
		src/map_functions.c\
		src/square_functions.c\
		src/square_engine.c\
		src/parser.c\
		src/solver.c\
		src/validation.c\
		src/print.c
SRC_DEBUG = \
		src/debug.c\
		src/map_functions.c\
		src/square_functions.c\
		src/square_engine.c\
		src/parser.c\
		src/solver.c\
		src/validation.c\
		src/print.c\

CFLAGS = -Wall -Wextra -Werror -g

OBJ = ${SRC:.c=.o}
OBJ_DEBUG = ${SRC_DEBUG:.c=.o}

NAME = bsq

.PHONY: all clean fclean re

%.o: %.c
	cc ${CFLAGS} -c $< -o $@ -I includes

all: ${NAME}

${NAME}: ${OBJ}
	cc ${CFLAGS} ${OBJ} -o ${NAME} -I includes

debug: ${OBJ_DEBUG}
	cc ${CFLAGS} ${OBJ_DEBUG} -o ${NAME} -I includes

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

