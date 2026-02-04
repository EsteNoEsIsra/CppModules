NAME = 

SRC = .cpp

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.c Makefile
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
