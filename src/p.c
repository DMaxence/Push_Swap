/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:11:32 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/18 15:50:27 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list_ps **a, t_list_ps **b)
{
	t_list_ps	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

static void	ft_end(t_list_ps **a, t_list_ps **b, char c, t_param *param)
{
	if (param->checker == 0)
	{
		ft_putchar('p');
		ft_putchar(c);
		ft_putchar('\n');
	}
	if (param->print == 1)
		ft_print_lst(*a, *b, param);
}

void		ft_pab(t_list_ps **a, t_list_ps **b, char c, t_param *param)
{
	if (c == 'a')
	{
		if (!((*b)))
			return ;
		else
		{
			ft_push(b, a);
			param->counta++;
			param->countb--;
		}
	}
	if (c == 'b')
	{
		if (!((*a)))
			return ;
		else
		{
			ft_push(a, b);
			param->counta--;
			param->countb++;
		}
	}
	ft_end(a, b, c, param);
}
