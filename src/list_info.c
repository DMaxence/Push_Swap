/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:34:03 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/02 17:50:05 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*sort_list(t_list_ps *lst)
{
	int			temp;
	t_list_ps	*tmp;
	t_list_ps	*start;

	start = lst;
	tmp = lst;
	while (lst)
	{
		while (tmp)
		{
			if (lst->nb > tmp->nb)
			{
				temp = lst->nb;
				lst->nb = tmp->nb;
				tmp->nb = temp;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
		tmp = lst;
	}
	ft_lst_free(tmp);
	return (start);
}

int			ft_lstlen_ps(t_list_ps *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int			ft_lst_last(t_list_ps *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->nb);
}
