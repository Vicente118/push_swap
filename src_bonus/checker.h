/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:51:47 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/20 19:43:07 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../source/push_swap.h"


// GNL
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *source);

void	input_error(t_stack *stack_a, t_stack *stack_b, char *line);

#endif