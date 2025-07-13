SRCS = main.cpp Brain.cpp A_Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

NAME = Abstract

OBJS := $(SRCS:%.cpp=%.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re