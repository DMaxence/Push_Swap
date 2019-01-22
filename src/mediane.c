/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:35:32 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/02 17:42:24 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_mediane(t_list_ps *lst, int nb)
{
	t_list_ps	*start;
	t_list_ps	*tmp;
	int			i;
	int			ret;

	if (!(tmp = ft_lst_dup(lst, nb)))
		return (-1);
	start = tmp;
	tmp = sort_list(tmp);
	nb /= 2;
	i = 0;
	while (i < nb)
	{
		ret = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	tmp = start;
	ft_lst_free(tmp);
	return (ret);
}

int		find_mediane_occurence(t_list_ps *lst, t_param *param, char c)
{
	while (lst)
	{
		if (lst->nb < param->mediane_tab[param->mediane] && c == '-')
		{
			return (1);
		}
		if (lst->nb >= param->mediane_tab[param->mediane] && c == '+')
		{
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int		check_max_down(t_list_ps *lst, int i)
{
	while (lst)
	{
		if (lst->nb > i)
			return (0);
		lst = lst->next;
	}
	return (1);
}
