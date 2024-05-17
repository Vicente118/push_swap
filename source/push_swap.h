/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:52:33 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/17 23:11:03 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

typedef enum s_Bool
{
	false,
	true
}	t_Bool;

typedef struct s_stack_node
{
	ssize_t				value;
	ssize_t				index;
	ssize_t				cost;
	t_Bool				above_median;
	struct s_stack_node	*best_friend;
	struct s_stack_node	*back;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	ssize_t				length;
	struct s_stack_node	*bottom;
	struct s_stack_node	*top;
}						t_stack;

// INIT_STACK
t_stack					*init_stack(void);
t_Bool					is_empty(t_stack *stack);
size_t					stack_length(t_stack *stack);
ssize_t					stack_node_top(t_stack *stack);
ssize_t					stackNode_bottom(t_stack *stack);
t_stack					*add_back_stack(t_stack *stack, ssize_t number);
t_stack					*fill_stack_a(int argc, char **argv);

// PRINT STACK
void					print_stack(t_stack *stack);

// ARGV ERROR
void					print_error(void);
t_Bool					check_doublon_error(ssize_t *tab);
t_Bool					check_argv_error(char **array);

// PARSER
ssize_t					length_array(char **array);
int						len_simple_array(ssize_t *array);
ssize_t					ft_big_atoi(char *str);
char					*argv_to_array(int argc, char **argv);
int						argv_count(int argc, char **argv);
ssize_t					*parser_simple_argv(char **argv);
ssize_t					*parser_multiple_argv(int argc, char **argv);
ssize_t					*argv_array_numbers(int argc, char **argv);

// FREE ARRAY
void					free_tab(char **array);
void					free_tab_error(char **array);
void					free_stack(t_stack_node **lst, t_stack *stack_a);

// MOVEMENT
void					swap(t_stack *stack);
void					swap2nodes(t_stack *stack);
void					sa(t_stack *stack_a);
void					sb(t_stack *stack_b);
void					ss(t_stack *stack_a, t_stack *stack_b);
void					pa(t_stack *stack_a, t_stack *stack_b);
void					pb(t_stack *stack_b, t_stack *stack_a);
void					rotation(t_stack *stack);
void					ra(t_stack *stack_a);
void					rb(t_stack *stack_b);
void					rr(t_stack *stack_a, t_stack *stack_b);
void					reverse_rotation(t_stack *stack);
void					rra(t_stack *stack_a);
void					rrb(t_stack *stack_a);
void					rrr(t_stack *stack_a, t_stack *stack_b);
void					ra_sa(t_stack *stack);

// ALGO UTILS
t_Bool					is_sort(t_stack *stack);
float					mean_value(t_stack *stack);
void					move_mean(t_stack *stack_a, t_stack *stack_b);
t_stack_node			*minimum_stack(t_stack *stack);
t_stack_node			*maximum_stack(t_stack *stack);
void					put_index(t_stack *stack);
void					put_median(t_stack *stack);
void					sort_3_nodes(t_stack *stack);
void					sort_2_nodes_b(t_stack *stack_a, t_stack *stack_b);
void					sort_4_nodes(t_stack *stack_a, t_stack *stack_b);
void					sort_5_nodes(t_stack *stack_a, t_stack *stack_b);
void					assign_best_friend(t_stack *stack_a, t_stack *stack_b);
void					assign_cost(t_stack *stack_a, t_stack *stack_b);
void					rise_node_b(t_stack *stack_b);
void					rise_node_bis(t_stack *stack_b);
void					rise_min_node(t_stack *stack_a, t_stack *stack_b);
int						find_best_cost(t_stack *stack_b, ssize_t *min);
void					rotate_to_rise(t_stack *s, t_stack_node *n, int index);

// FINAL FONCTION
void					push_swap(t_stack *stack_a, t_stack *stack_b);

#endif
