RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 


NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c ft_utils.c ft_utils2.c		 

OBJS = $(SRCS:.c=.o)

ARRC = ar rc



RM = rm -f

TOTAL_FILES 	:= $(words $(SRCS))

CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(GREEN)Compiling printf... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef


.c.o : $(SRCS)
	@${CC} ${CFLAGS} -c -o $@ $^
	$(call progress_bar_push_swap)

$(NAME) : $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re