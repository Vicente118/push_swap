RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

CC = cc 

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g

RM = rm -rf

SRCS = 	source/push_swap.c\
		source/init_stack.c\
		source/linked_list_movement.c\
		source/print_stack.c\
		source/parsing.c\
		source/fill_stack_a.c\
		source/swap_movement.c\
		source/push_movement.c\
		source/rotation_movement.c\
		source/reverse_rotation_movement.c\
		source/algorithme2.c\
		source/algorithme1.c\
		source/algorithme_utils.c\
		source/extremum_stack.c\
		source/free_tab.c\
		source/ft_big_atoi.c\
		source/argv_to_array.c\
		source/error_message.c\

OBJS	=	$(SRCS:.c=.o)

SRCS_BONUS = src_bonus/checker.c\
			 get_next_line/get_next_line.c\
			 get_next_line/get_next_line_utils.c\
# 			src_bonus/ope1_bonus.c\
# 			src_bonus/ope2_bonus.c\
# 			src_bonus/ope3_bonus.c\
# 			src_bonus/ope4_bonus.c\
# 			src_bonus/utils_bonus.c\

OBJS2	=	$(SRCS_BONUS:.c=.o)

TOTAL_FILES 	:= $(words $(SRCS))

CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(GREEN)Compiling Push Swap... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@make -C printf
	@printf "                                               \r"
	@echo "                       								 "        			
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "                       								 "        			
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIBFT) $(PRINTF)

$(BONUS) : $(OBJS) $(OBJS2) 
	@make bonus -C libft
	@make -C printf
	@printf "                                               \r"
	@echo "                       								 "        			
	@echo " ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ "
	@echo "██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗"
	@echo "██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝"
	@echo "██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗"
	@echo "╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║"
	@echo " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "                       								 "
	@$(CC) $(OBJS2) $(CFLAGS) -o $(NAME_BONUS) $(LIBFT) $(PRINTF)

%.o : %.c	
	@$(CC) -o $@ -c $< $(CFLAGS)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C printf
	@make fclean -C libft
	@rm -rf push_swap checker

clean :
	@$(RM) $(NAME)
	@make clean -C printf
	@make clean -C libft
	@rm -rf source/*.o src_bonus/*.o

re : fclean all