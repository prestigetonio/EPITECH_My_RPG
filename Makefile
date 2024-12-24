##
## EPITECH PROJECT, 2024
## makefile
## File description:
## emacs
##

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = my_rpg

SRC =	src/main.c           \
		src/basic/create.c\
		src/basic/destroy.c\
		src/player/attack.c	\
		src/player/manage.c	\
		src/player/player.c	\
		src/map/collision.c	\
		src/npc/create.c	\
		src/npc/destroy.c	\
		src/npc/npc.c	\
		src/npc/dialogue.c	\
		src/rat/create_mob.c	\
		src/rat/destroy_mob.c	\
		src/rat/display_mob.c	\

OBJ =  $(SRC:.c=.o)

CFLAGS = -I ./include

LIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@echo -e "$(YELLOW)■-■-■ COMPILATION GOOD ■-■-■$(NC)"
	gcc -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)
	@echo -e "$(GREEN)■-■-■-■-■-■ GOOD ■-■-■-■-■$(NC)"

all : $(NAME)

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#
	rm -f vgcore.*
	rm -f *.log
	@echo -e "$(GREEN)CLEAN$(NC)"

fclean : clean
	@echo -e "$(RED)CLEAN -> $(NAME)...$(NC)"
	rm -f $(NAME)
	@echo -e "$(GREEN)■-■-■-■-■ GOOD ■-■-■-■-■$(NC)"

re : fclean all
