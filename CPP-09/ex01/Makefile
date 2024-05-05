# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# VARIABLES

SRCS	=	$(wildcard *.cpp)
OBJS	=	${SRCS:.cpp=.o}
NAME	=	RPN
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
# RULES

%.o:	%.cpp
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
	@echo "$(BLUE)Compiling $<...$(END_COLOR)"

$(NAME):	${OBJS}
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
	@rm -f ${OBJS}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"

re:		fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)!$(END_COLOR)"

.PHONY:	all clean fclean re%
