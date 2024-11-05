CC = gcc
SRCS_DIR = srcs/
INCLUDES = includes/
CFLAGS =  -Wall -Wextra -Werror -I${INCLUDES}
SRCS = ${SRCS_DIR}ft_putchar.c ${SRCS_DIR}ft_putstr.c ${SRCS_DIR}ft_strcmp.c ${SRCS_DIR}ft_strlen.c ${SRCS_DIR}ft_swap.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
