SRC = philosophers.c ft_atoi.c philosophers_utils.c philosophers_utils_2.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean : 

fclean :
	rm -f $(NAME)

re : fclean all