RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME = push_swap

CC = cc 

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = 	source/push_swap.c\
		source/init_stack.c\
		source/linked_list_movement.c\
		source/print_stack.c\
		source/parsing.c\
		source/free_tab.c\
		source/ft_big_atoi.c\
		source/argv_to_array.c\
		source/error_message.c\
		printf/libftprintf.a\
		libft/libft.a\

# SRCS_BONUS = src_bonus/checker_bonus.c\
# 			src_bonus/ope1_bonus.c\
# 			src_bonus/ope2_bonus.c\
# 			src_bonus/ope3_bonus.c\
# 			src_bonus/ope4_bonus.c\
# 			src_bonus/utils_bonus.c\
# 			libft/libft.a\

TOTAL_FILES 	:= $(words $(SRCS))

CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(GREEN)Compiling Push Swap... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(NAME) :
	@make bonus -C libft
	@make -C printf
	$(call progress_bar_push_swap)
	@$(CC) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C printf
	@make fclean -C libft

clean :
	@$(RM) $(NAME)
	@make clean -C printf
	@make clean -C libft

re : fclean all

bonus : 
	@make bonus -C libft
	@make -C printf
	@gcc $(CFLAGS) $(SRCS_BONUS) -o checker

