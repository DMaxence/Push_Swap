/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:02:53 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/25 20:08:53 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include "push_swap.h"
# include <stdarg.h>

typedef struct		s_list_b
{
	char			*str;
	struct s_list_b	*next;
}					t_list_order;

int					main(int argc, char **argv);
t_list_order		*ft_node_order_new(char *str);
t_list_order		*ft_order_add_end(t_list_order *lst, char *str);
int					order_chooser(t_list_ps **a, t_list_ps **b, \
	t_list_order *order, t_param *param);
int					ft_isnumber(const char *str);
int					executor(t_list_ps **a, t_list_order *order);
int					checker_check(char **args);
int					check_order(char *str);
int					ft_isnumber(const char *str);
int					ft_mainck_solo(char **argv);
int					ft_mainck_multiple(char **argv);
void				ft_order_free(t_list_order *lst);

#endif
