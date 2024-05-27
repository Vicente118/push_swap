RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

CC = cc 

CFLAGS = -Werror -Wall -Wextra

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

SRCS_BONUS = src_bonus/checker_bonus.c\
			 src_bonus/get_next_line_bonus.c\
			 src_bonus/get_next_line_utils_bonus.c\
			 source/linked_list_movement.c\
			 source/print_stack.c\
			 source/parsing.c\
			 source/fill_stack_a.c\
			 src_bonus/swap_movement_bonus.c\
		  	 src_bonus/push_movement_bonus.c\
		 	 src_bonus/rotation_movement_bonus.c\
			 src_bonus/reverse_rotation_movement_bonus.c\
			 src_bonus/init_stack_bonus.c\
			 source/algorithme2.c\
			 source/algorithme1.c\
			 source/algorithme_utils.c\
			 source/extremum_stack.c\
			 source/free_tab.c\
			 source/ft_big_atoi.c\
			 source/argv_to_array.c\
			 source/error_message.c\
		

OBJS2	=	$(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@printf "                                               \r"
	@echo "                       								 "        			
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "                       								 "        			
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(BONUS) : $(OBJS) $(OBJS2) 
	@make bonus -C libft
	@printf "                                               \r"
	@echo "                       								 "        			
	@echo " ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ "
	@echo "██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗"
	@echo "██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝"
	@echo "██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗"
	@echo "╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║"
	@echo " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "                       								 "
	@$(CC) $(CFLAGS) $(OBJS2) $(LIBFT) $(PRINTF) -o $(BONUS)

%.o : %.c	
	@$(CC) $(CFLAGS) -o $@ -c $< 

fclean : clean
	@make fclean -C libft
	@rm -rf push_swap checker

clean :
	@make clean -C libft
	@rm -rf source/*.o src_bonus/*.o

re : fclean all