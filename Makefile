NAME = philo

C_FILES = main.c\
			utils.c\
			routine.c\
			parthing.c\

SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Werror -Wextra -I includes/ -g

all: ${NAME}

${NAME}: ${SRCS}
	cc ${CFLAGS} ${SRCS} -o ${NAME}

clean:
		@printf "FREE PALESTINE\n"

fclean:	clean
		rm -rf ${NAME}

re:             fclean all

.PHONY:         all clean fclean re
