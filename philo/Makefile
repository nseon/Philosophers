# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 10:00:18 by nseon             #+#    #+#              #
#    Updated: 2025/04/23 16:54:52 by nseon            ###   ########.fr        #
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

# --------------THREADS-------------- #

SRC			+=	$(addprefix $(TRD_DIR), $(TRD_SRC))

TRD_DIR		=	threads/
TRD_SRC		=	create_threads.c\

# --------------VECTOR--------------- #

SRC			+=	$(addprefix $(VCT_DIR), $(VCT_SRC))

VCT_DIR		=	vector/
VCT_SRC		=	vector.c\
				vector_data.c\
				vector_infos.c\
				vector_clean.c\
				vector_allocs.c\

# --------------UTILS---------------- #

SRC			+=	$(addprefix $(TLS_DIR), $(TLS_SRC))

TLS_DIR		=	utils/
TLS_SRC		=	ft_atoi.c\
				ft_strlen.c\
				ft_memcpy.c\
				ft_strdup.c\
				ft_realloc.c\
				ft_memmove.c\

# -------------PARSING--------------- #

SRC			+=	$(addprefix $(PRS_DIR), $(PRS_SRC))

PRS_DIR		=	parsing/
PRS_SRC		=	check_args.c\
				get_args.c\

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
	@valgrind --tool=helgrind --history-level=approx ./philo 4 4 4 4

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
