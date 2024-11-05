CC = gcc
SRCS_DIR = srcs/
INCLUDES = includes/
CFLAGS =  -Wall -Wextra -Werror -I${INCLUDES}
SRCS = \
		${SRCS_DIR}dict.c\
		${SRCS_DIR}dict_to_array.c\
		${SRCS_DIR}parser.c\
		${SRCS_DIR}utils.c\
		${SRCS_DIR}utils2.c\
		${SRCS_DIR}utils3.c\
		${SRCS_DIR}ft_split.c\
		${SRCS_DIR}ft_atoi.c\
		${SRCS_DIR}file_manager.c\
		${SRCS_DIR}blueprint.c\
		${SRCS_DIR}main.c\
		${SRCS_DIR}memory.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02

all : $(NAME)

$(NAME) : ${OBJS}
	${CC} ${CFLAGS} -g ${OBJS} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}
