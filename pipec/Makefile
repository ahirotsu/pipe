NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c error.c c_split.c cmdch_sub.c pipex.c check_arg.c ft_split.c ft_strjoin.c ft_strncmp.c ft_strdup.c ft_strlen.c check_pa.c
OBJS = ${SRC:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS}  -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o