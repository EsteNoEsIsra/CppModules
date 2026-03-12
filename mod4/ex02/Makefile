NAME = abstract

SRC = AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp Brain.cpp
HDR = AAnimal.h	Cat.h Dog.h WrongAnimal.h WrongCat.h Brain.h
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb
RM = rm -rf
OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(OBJS_DIR)/%.o : %.cpp $(HDR) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS_DIR)
		 
fclean: clean
	$(RM) $(NAME)
re: fclean all 

.PHONY: all clean fclean re 
