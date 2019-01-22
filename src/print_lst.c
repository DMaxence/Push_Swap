/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:46:08 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/18 16:37:25 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	ft_print_lst_while(t_list_ps **a, t_list_ps **b, t_param *param)
{
	int		i;

	i = 1;
	system("clear");
	ft_printf("==lst a : ==     ==lst b : ==\n");
	while ((*a && i <= param->counta - param->nb_tri) || *b)
	{
		if (*a)
		{
			ft_printf("     \033[31m %d\033[0m", (*a)->nb);
			*a = (*a)->next;
			i++;
		}
		else
			ft_printf("       ");
		if (*b)
		{
			ft_printf("               \033[31m %d\033[0m\n", (*b)->nb);
			*b = (*b)->next;
		}
		else
			ft_printf("\n");
	}
}

void		ft_print_lst(t_list_ps *lsta, t_list_ps *lstb, t_param *param)
{
	t_list_ps	*a;
	t_list_ps	*b;

	a = lsta ? lsta : NULL;
	b = lsta ? lstb : NULL;
	if (a && a->nb)
	{
		ft_print_lst_while(&a, &b, param);
		while (a || b)
		{
			if (a)
			{
				ft_printf("     \033[32m %d\033[0m\n", a->nb);
				a = a->next;
			}
			else
				ft_printf("       ");
			if (b)
			{
				ft_printf("               \033[31m %d\033[0m", b->nb);
			}
		}
	}
}
