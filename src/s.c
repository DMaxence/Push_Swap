/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:16:39 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/03 15:44:48 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab(t_list_ps **a, t_list_ps **b, char c, t_param *param)
{
	int			temp;

	(void)param;
	if (!((*a)) || !((*a)->next))
		return ;
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	if (param->checker == 0)
	{
		ft_putchar('s');
		ft_putchar(c);
		ft_putchar('\n');
	}
	if (param->print == 1)
		ft_print_lst(*a, *b, param);
}

void	ft_ss(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int			temp;

	(void)param;
	if (!((*a)) || !((*a)->next) || !((*b)) || !((*b)->next))
		return ;
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	temp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = temp;
	if (param->checker == 0)
		ft_putstr("ss\n");
	if (param->print == 1)
		ft_print_lst(*a, *b, param);
}
