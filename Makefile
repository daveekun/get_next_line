NAME = get_next_line.a
CC = cc
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

