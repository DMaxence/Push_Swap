/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:29:03 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/10 16:41:36 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_list_ps **lst)
{
	t_list_ps	*temp;
	t_list_ps	*temp2;

	if (!(*lst)->next)
		return ;
	temp = *lst;
	temp2 = *lst;
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *lst;
	*lst = temp;
	temp2->next = NULL;
}

void		ft_rrotate(t_list_ps **a, t_list_ps **b, char c, t_param *param)
{
	if (c == 'a' && (*a))
		ft_reverse_rotate(a);
	else if (c == 'b' && (*b))
		ft_reverse_rotate(b);
	else if (c == 'r')
	{
		if ((*a))
			ft_reverse_rotate(a);
		if ((*b))
			ft_reverse_rotate(b);
	}
	if (param->checker == 0)
	{
		ft_putstr("rr");
		ft_putchar(c);
		ft_putchar('\n');
	}
	if (param->print == 1)
		ft_print_lst(*a, *b, param);
}
