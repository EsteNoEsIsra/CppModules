NAME = intern

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp\
	 RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
HDR = Bureaucrat.h AForm.h PresidentialPardonForm.h RobotomyRequestForm.h\
		 ShrubberyCreationForm.h Intern.h
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
