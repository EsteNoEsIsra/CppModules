NAME = Zombie00

SRC = newZombie.cpp randomChump.cpp Zombie.cpp  main.cpp
HDR = Zombie.hpp Zombie.h
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
OBJS_DIR = objs

OBJS =  $(OBJS_DIR)/$(SRC:.cpp=.o)

all : $(NAME)

$(OBJS_DIR)/%.o : %.cpp Makefile
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) 
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
		$(RM) $(OBJS)
		 
fclean:
		$(RM) $(OBJS)
		$(RM) $(NAME)
re: fclean all 

.PHONY: all clean fclean re 
