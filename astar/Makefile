##
## Makefile for dante in /home/thibrex/Dropbox/delivery/CPE/dante/astar
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Fri May 12 10:14:01 2017 Thibaut Cornolti
## Last update Sat May 13 17:36:07 2017 Thibaut Cornolti
##

SRC		=	main.c				\
			astar.c				\
			param.c				\
			stack.c

OBJ		=	$(SRC:.c=.o)

NAME		=	solver

INCLUDE		=	-I./include/

CFLAGS		+=	 $(INCLUDE) -W -Wall -Wextra -pedantic -O3

REDDARK         =       \033[31;2m

RED             =       \033[31;1m

GREEN           =       \033[32;1m

YEL             =       \033[33;1m

BLUE            =       \033[34;1m

PINK            =       \033[35;1m

CYAN            =       \033[36;1m

RES             =       \033[0m

all:		$(NAME)

$(NAME): 	$(OBJ)
		@echo
		@echo "$(GREEN)Everything compiled smoothly. Now compiling dependancies...$(RES)"
		@echo
		@echo "$(CYAN)Linking $(NAME)...$(RES)"
		@gcc -o $(NAME) $(OBJ)
		@echo "\t$(GREEN)OK$(RES)$(CYAN)!$(RES)"
		@echo
		@echo "$(GREEN)---- $(NAME) READY ----$(RES)"
		@echo

clean:
		@$(foreach var, $(OBJ), if [ -e $(var) ] ; then \
		printf "[$(RED)RM$(RES)] $(YEL)$(var)$(RES)\n" \
		&& $(RM) $(var) ; fi ;)
		@rm -f $(OBJ)
		@echo "$(GREEN)---- $(NAME) CLEANED ----$(RES)"
		@echo

fclean:		clean
		@if [ -e $(NAME) ] ; then \
		printf "[$(RED)RM EXEC$(RES)] $(YEL)$(NAME)$(RES)\n" \
		&& rm -f $(NAME) ; fi
		@rm -f $(NAME)
		@echo "$(GREEN)---- $(NAME) REMOVED ----$(RES)"
		@echo


re: 		fclean all

%.o:		%.c
		@echo "[$(RED)COMPILE$(RES)] $(YEL)$<$(RES) $(BLUE)=>$(RES) $(YEL)$@$(RES)"
		@gcc $(CFLAGS) -o $@ -c $<

.PHONY: 	all clean fclean re
