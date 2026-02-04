NAME = Account

SRC = Account.cpp tests.cpp
HDR = Account.hpp

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp Makefile $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)
		 
fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
