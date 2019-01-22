/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:37:14 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/18 15:44:42 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repush_a(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int		i;

	i = 0;
	if (!(*b) || param->mediane < 0)
		return ;
	param->mediane--;
	if (param->mediane < 0)
	{
		param->mediane++;
		param->mediane_tab[param->mediane] = find_mediane(*b, ft_lstlen_ps(*b));
	}
	while (find_mediane_occurence(*b, param, '+') == 1)
	{
		if ((*b)->nb >= param->mediane_tab[param->mediane])
		{
			ft_pab(a, b, 'a', param);
		}
		else
			ft_r(a, b, 'b', param);
	}
	if (param->nb_tri == param->counta && param->mediane > 0)
		repush_a(a, b, param);
}

void	keepthree(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if (param->counta - param->nb_tri <= 3)
		return ;
	param->mediane++;
	param->mediane_tab[param->mediane] = find_mediane(*a, param->counta - \
		param->nb_tri);
	while (find_mediane_occurence(*a, param, '-') == 1)
	{
		if ((*a)->nb < param->mediane_tab[param->mediane])
		{
			ft_pab(a, b, 'b', param);
		}
		else
			ft_r(a, b, 'a', param);
	}
	if (param->counta > 3 && param->mediane < 255 && param->mediane > 0)
	{
		while (check_max_down((*a), ft_lst_last(*a)) == 0)
		{
			ft_rrotate(a, b, 'a', param);
		}
		keepthree(a, b, param);
	}
}

void	dividor(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int			i;

	param->mediane_tab[param->mediane] = find_mediane(*a, ft_lstlen_ps(*a));
	while (find_mediane_occurence(*a, param, '-') == 1)
	{
		if ((*a)->nb < param->mediane_tab[param->mediane])
		{
			ft_pab(a, b, 'b', param);
		}
		else
			ft_r(a, b, 'a', param);
	}
	if (param->counta > 3 && param->mediane < 256)
	{
		param->mediane++;
		dividor(a, b, param);
	}
	i = 0;
	while (i < 20)
	{
		i++;
	}
}
