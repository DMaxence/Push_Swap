/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:39:06 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/03 15:46:33 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_param		*param_start(t_list_ps *a, int print)
{
	int		i;
	t_param *param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->mediane = 0;
	i = -1;
	while (++i < 256)
		param->mediane_tab[i] = 0;
	i = 0;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	param->total = i + 1;
	param->nb_tri = 0;
	param->counta = i + 1;
	param->countb = 0;
	param->print = print;
	param->checker = 0;
	return (param);
}

int			verif_trif(t_list_ps *lst, t_param *param)
{
	t_list_ps	*start;
	int			temp;

	start = lst;
	temp = lst->nb;
	while (lst)
	{
		if (temp > lst->nb)
			return (1);
		temp = lst->nb;
		lst = lst->next;
	}
	param->nb_tri = ft_lstlen_ps(start);
	return (0);
}
