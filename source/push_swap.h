#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/types.h>

typedef enum s_Bool
{
	false, // 0
	true   // 1
}	t_Bool;

typedef struct s_stackNode
{
	ssize_t				value;
	ssize_t				index;
	struct s_stackNode	*back;
	struct s_stackNode	*next;
}	t_stackNode;

typedef struct s_stack
{
	ssize_t				length;
	struct s_stackNode	*bottom;
	struct s_stackNode	*top;
}	t_stack;

// INIT_STACK
t_stack *init_stack(void);
t_Bool	is_empty(t_stack *stack);
ssize_t	stack_length(t_stack *stack);
ssize_t	stackNode_top(t_stack *stack);
ssize_t stackNode_bottom(t_stack *stack);
t_stack *add_back_stack(t_stack *stack, ssize_t number);
t_stack	*fill_stackA(int argc, char **argv);

// PRINT STACK
void	print_stack(t_stack *stack);

// ARGV ERROR
void    print_error(void);
t_Bool	check_doublon_error(ssize_t *tab);
t_Bool  check_argv_error(char **array);

// PARSER
ssize_t length_array(char **array);
int		len_simple_array(ssize_t *array);
ssize_t	ft_big_atoi(char *str);
char    *argv_to_array(int argc, char **argv);
int     argv_count(int argc, char **argv);
ssize_t	*parser_simple_argv(char **argv);
ssize_t *parser_multiple_argv(int argc, char  **argv);
ssize_t	*argv_array_numbers(int argc, char **argv);

// FREE ARRAY
void    free_tab(char **array);
void    free_tab_error(char **array);
void	free_stack(t_stackNode **lst);

// MOVEMENT
void    sa(t_stack *stackA);
void    sb(t_stack *stackB);
void    ss(t_stack *stackA, t_stack *stackB);
void    pa(t_stack *stackA, t_stack *stackB);
void    pb(t_stack *stackB, t_stack *stackA);

//FINAL FONCTION
void	push_swap(int argc, char **argv);

#endif