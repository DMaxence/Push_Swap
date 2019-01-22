/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:18:13 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/10 16:40:53 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list_ps **lst)
{
	t_list_ps	*temp;

	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = *lst;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
}

void		ft_r(t_list_ps **a, t_list_ps **b, char c, t_param *param)
{
	if (c == 'a' && (*a))
		ft_rotate(a);
	else if (c == 'b' && (*b))
		ft_rotate(b);
	else if (c == 'r')
	{
		if ((*a))
			ft_rotate(a);
		if ((*b))
			ft_rotate(b);
	}
	if (param->checker == 0)
	{
		ft_putchar('r');
		ft_putchar(c);
		ft_putchar('\n');
	}
	if (param->print == 1)
		ft_print_lst(*a, *b, param);
}
