
SRC = get_next_line.c \
	get_next_line_utils.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

DEP = $(OBJ:.o=.d)

NAME = getnextline.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
