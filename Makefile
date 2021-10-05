NAME = a.out
SRC = main.c get_args.c execute_server.c server.c execute_philos.c philosof.c\
philo_eat.c philo_think.c philo_sleep.c utils.c
HEADER = philos.h
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean