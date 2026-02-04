NAME = phonebook

SRC = main.cpp Contact.cpp PhoneBook.cpp
HDR = Contact.hpp PhoneBook.hpp

CC = c++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98

RM = rm -rf

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp Makefile $(HDR)
		$(CC) $(FLAGS)  -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
		$(RM) $(OBJS)
		 
fclean:
		$(RM) $(OBJS)
		$(RM) $(NAME)
re: fclean all 

.PHONY: all clean fclean re 
