/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:41:17 by maduhoux          #+#    #+#             */
/*   Updated: 2018/07/04 00:40:46 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	complement(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if ((*a)->next->nb > (*a)->next->next->nb)
	{
		ft_r(a, b, 'a', param);
		ft_sab(a, b, 'a', param);
		sort_three(a, b, param);
	}
}

void		sort_two(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if (verif_trif(*a, param) == 0)
		return ;
	if ((*a)->nb > (*a)->next->nb)
	{
		ft_r(a, b, 'a', param);
		sort_three(a, b, param);
	}
}

void		sort_three(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if (verif_trif(*a, param) == 0)
		return ;
	if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
	{
		ft_r(a, b, 'a', param);
		sort_three(a, b, param);
	}
	if ((*a)->nb > (*a)->next->nb)
	{
		ft_sab(a, b, 'a', param);
		sort_three(a, b, param);
	}
	if ((*a)->nb > (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
	{
		ft_rrotate(a, b, 'a', param);
		sort_three(a, b, param);
	}
	if ((*a)->next->next->nb < (*a)->nb)
	{
		ft_rrotate(a, b, 'a', param);
		sort_three(a, b, param);
	}
	complement(a, b, param);
}

void		trithree(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if ((*a)->nb < (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb &&
			(*a)->next->next->nb < (*a)->next->next->next->nb)
		return ;
	if ((*a)->next->next->next->nb < (*a)->next->next->nb && param->counta > 3)
	{
		ft_r(a, b, 'a', param);
		ft_r(a, b, 'a', param);
		ft_sab(a, b, 'a', param);
		ft_rrotate(a, b, 'a', param);
		ft_rrotate(a, b, 'a', param);
		trithree(a, b, param);
	}
	if ((*a)->nb > (*a)->next->nb)
	{
		ft_sab(a, b, 'a', param);
		trithree(a, b, param);
	}
	if ((*a)->next->nb > (*a)->next->next->nb)
	{
		ft_r(a, b, 'a', param);
		ft_sab(a, b, 'a', param);
		ft_rrotate(a, b, 'a', param);
		trithree(a, b, param);
	}
}
