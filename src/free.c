/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:21:52 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/25 19:21:33 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void		ft_lst_free(t_list_ps *lst)
{
	t_list_ps	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}

void		ft_order_free(t_list_order *lst)
{
	t_list_order	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = tmp->next;
		free(tmp->str);
		free(tmp);
	}
	lst = NULL;
}

void		ft_free_arr(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void		ft_exit(int keycode)
{
	if (keycode == 0)
		exit(1);
	if (keycode == -1)
		ft_putendl("Error malloc");
	if (keycode == 1)
		ft_putendl("Error");
	exit(0);
}
