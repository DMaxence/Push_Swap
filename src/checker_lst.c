/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:51:17 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/03 17:23:32 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list_order	*ft_node_order_new(char *str)
{
	t_list_order	*new;

	if (!(new = (t_list_order *)malloc(sizeof(t_list_order))))
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

t_list_order	*ft_order_add_end(t_list_order *lst, char *str)
{
	t_list_order	*new_element;
	t_list_order	*temp;

	if (!(new_element = ft_node_order_new(str)))
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
