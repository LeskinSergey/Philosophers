NAME = philo
SRC = philo.c\
		philo_1.c\
		philo_2.c\
		atoi.c\

HDR = philo.h
OBJ = $(SRC:%.c=%.o)
CC = cc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
		$(CC) $(OBJ) -o $(NAME)
clean:
	-rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
