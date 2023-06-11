# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 18:56:35 by thabeck-          #+#    #+#              #
#    Updated: 2023/06/10 20:51:38 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

SRCS			= $(wildcard src/*.c)
OBJS			= ${SRCS:src/%.c=obj/%.o}
HEADER			= inc/philo.h inc/structs.h
OBJS_DIR		= obj/

RM				= rm -fr
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -pthread

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "\n$(CY)Generating philo executable...$(RC)\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "$(GR)Done!$(RC)\n\n"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

obj/%.o: src/%.c
	@printf "\r$(CY)Generating objects...$(RC)"
	@${CC} ${FLAGS} -c $< -o ${<:src/%.c=obj/%.o}
	@printf "$(RC)                              "

norm:
	@norminette ${SRCS} ${HEADER}

clean:
	@$(RM) $(OBJS_DIR)
	@printf "$(RE)philo objects removed!$(RC)\n"

fclean:		clean
	@$(RM) $(NAME)
	@printf "$(RE)philo executable removed!$(RC)\n\n"

re:			fclean all

.PHONY:		all clean fclean re
