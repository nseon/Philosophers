# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 10:00:18 by nseon             #+#    #+#              #
#    Updated: 2025/05/13 10:50:02 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	src/

OBJ			=	$(patsubst %.c, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.c, $(MAKE_DIR)%.d, $(SRC))

# ---------------MAIN---------------- #

SRC			=	philo.c\

# ---------------TIME---------------- #

SRC			+=	$(addprefix $(TIM_DIR), $(TIM_SRC))

TIM_DIR		=	time/
TIM_SRC		=	get_time.c\

# --------------THREADS-------------- #

SRC			+=	$(addprefix $(TRD_DIR), $(TRD_SRC))

TRD_DIR		=	threads/
TRD_SRC		=	threads.c\
				routine.c\

# --------------ACTIONS-------------- #

SRC			+=	$(addprefix $(ACT_DIR), $(ACT_SRC))

ACT_DIR		=	actions/
ACT_SRC		=	forks.c\
				eat.c\
				sleep.c\
				dead.c\
				think.c\
				print.c\

# --------------UTILS---------------- #

SRC			+=	$(addprefix $(TLS_DIR), $(TLS_SRC))

TLS_DIR		=	utils/
TLS_SRC		=	ft_atoi.c\
				ft_strdup.c\
				ft_strlen.c\

# -------------PARSING--------------- #

SRC			+=	$(addprefix $(PRS_DIR), $(PRS_SRC))

PRS_DIR		=	parsing/
PRS_SRC		=	check_args.c\
				infos.c\

# -------------INCLUDES-------------- #

INC_DIR 	=	includes/
INCLUDES	=	$(INC_DIR)\
				$(addsuffix $(INC_DIR), $(dir $(LIB_PATH)))

# --------------CONFIGS-------------- #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIB))

# --------------TARGETS-------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(LIB_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(MAKE_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB_PATH): force
	$(MAKE) -C $(@D)

.PHONY: norminette
norminette:
	norminette $(INC_DIR) $(SRC_DIR)

.PHONY: helgrind
helgrind: all
	@valgrind --tool=helgrind --history-level=approx -s ./philo 10 4000 50 50

.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(NAME) $(MAKE_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: force
force:

-include $(DEP)

.DEFAULT_GOAL := all
