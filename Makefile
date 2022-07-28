
#Colors:
########################
BOLD = \033[1m
BLUE = \033[0;34m
CYAN = \033[36m
GREEN = \033[32m
ORANGE = \033[93m
PURPLE = \033[0;95m
RED = \033[0;91m
END = \033[0m
########################

NAME	        =		push_swap

NAME_B          =       push_swap_bonus

SRCS            =       $(wildcard srcs/*.c)

SRCS_B      =       $(wildcard bonus/srcs_bonus/*.c)

INCLUDES_DIR     =       includes/

INCLUDES_DIR_B  =       bonus/includes_bonus/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

RM          =       rm -rf

FLAGS       =       -Wall -Wextra -Werror -g3

%.o : %.c ./includes/push_swap.h
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
						@echo "\t\t${BOLD}${GREEN}[LOADED]${END} ${PURPLE}${<:.s=.o}${END}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${LIB_DIR} 2>/dev/null
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT}
						@echo "\t\t${BOLD}${CYAN} libft.a${END}   ${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}push_swap${END}   ${GREEN}[ OK ]${END}"
bonus:		${OBJS_B}
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} -I${INCLUDES_DIR_B} -o ${NAME_B} ${OBJS_B} ${LIBFT}
						@echo "\t\t${BOLD}${CYAN} libft.a${END}   ${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}push_swap_bonus${END}   ${GREEN}[ OK ]${END}"
clean:
						@make -C ${LIB_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n${BOLD}${RED}\t\t *.o files deleted.${END}"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\t\t${BOLD}${RED}libft.a deleted.${END}"
						@echo "\t\t${BOLD}${RED}Program push_swap deleted.${END}"
						@echo "\t\t${BOLD}${RED}Program push_swap_bonus deleted.${END}"

re:		fclean all

.PHONY:           all     clean   fclean  re
