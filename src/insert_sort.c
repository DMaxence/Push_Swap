/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:43:16 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/18 15:56:30 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		find_min(t_list_ps *lst)
{
	int		i;

	i = lst->nb;
	while (lst)
	{
		if (lst->nb < i)
			i = lst->nb;
		lst = lst->next;
	}
	return (i);
}

int		find_max(t_list_ps *lst)
{
	int		i;

	i = lst->nb;
	while (lst)
	{
		if (lst->nb > i)
			i = lst->nb;
		lst = lst->next;
	}
	return (i);
}

int		find_pos(t_list_ps *lst, int nb)
{
	int		i;

	i = 1;
	while (lst)
	{
		if (lst->nb == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

void	insert_a(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int		min;
	int		pos;

	min = find_min(*a);
	pos = find_pos(*a, min);
	if (param->counta <= 3 && verif_trif(*a, param) != 0)
		sort_three(a, b, param);
	if ((*a)->nb == min && verif_trif(*a, param) != 0)
		ft_pab(a, b, 'b', param);
	else if (verif_trif(*a, param) != 0)
	{
		if (pos <= ft_lstlen_ps(*a) / 2)
			ft_r(a, b, 'a', param);
		else
			ft_rrotate(a, b, 'a', param);
	}
	if (!(*a) || verif_trif(*a, param) == 0)
	{
		while ((*b))
			ft_pab(a, b, 'a', param);
	}
	else
		insert_a(a, b, param);
}

void	insert_b(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int		max;
	int		pos;

	max = find_max(*b);
	pos = find_pos(*b, max);
	if ((*b)->nb == max)
		ft_pab(a, b, 'a', param);
	else
	{
		if (pos < ft_lstlen_ps(*a) / 2)
			ft_r(a, b, 'b', param);
		else
			ft_rrotate(a, b, 'b', param);
	}
	if ((*b))
	{
		insert_b(a, b, param);
	}
}
