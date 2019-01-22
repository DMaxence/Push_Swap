/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:13:31 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/25 13:22:29 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_node_new(int nb)
{
	t_list_ps	*new;

	if (!(new = (t_list_ps *)malloc(sizeof(t_list_ps))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_list_ps	*ft_lst_add_end(t_list_ps *lst, int nbr)
{
	t_list_ps	*new_element;
	t_list_ps	*temp;

	if (!(new_element = ft_node_new(nbr)))
		return (NULL);
	if (lst == NULL)
		return (new_element);
	else
	{
		temp = lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_element;
		return (lst);
	}
}

t_list_ps	*ft_lst_dup(t_list_ps *lst, int nb)
{
	t_list_ps	*newlst;
	t_list_ps	*tmp;

	tmp = lst;
	if (!(newlst = ft_node_new(tmp->nb)))
		return (NULL);
	tmp = tmp->next;
	while (tmp)
	{
		if (nb == 1)
			return (newlst);
		if (!(newlst = ft_lst_add_end(newlst, tmp->nb)))
			return (NULL);
		tmp = tmp->next;
		nb--;
	}
	ft_lst_free(tmp);
	return (newlst);
}
