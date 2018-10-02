##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Sun May 14 02:17:02 2017 Thibaut Cornolti
##

ASTAR		=	./astar

DEPTH		=	./depth

BREADTH		=	./breadth

TOURNAMENT	=	./tournament

GENERATOR	=	./generator

all:
	@make -C $(ASTAR)
	@make -C $(DEPTH)
	@make -C $(BREADTH)
	@make -C $(TOURNAMENT)
	@make -C $(GENERATOR)

clean:
	@make clean -C $(ASTAR)
	@make clean -C $(DEPTH)
	@make clean -C $(BREADTH)
	@make clean -C $(TOURNAMENT)
	@make clean -C $(GENERATOR)

fclean:	clean
	@make fclean -C $(ASTAR)
	@make fclean -C $(DEPTH)
	@make fclean -C $(BREADTH)
	@make fclean -C $(TOURNAMENT)
	@make fclean -C $(GENERATOR)

re:	fclean all
