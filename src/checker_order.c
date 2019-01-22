/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:52:35 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/25 20:11:34 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int		order_chooser(t_list_ps **a, t_list_ps **b, t_list_order *order, \
	t_param *param)
{
	if (ft_strcmp(order->str, "ra") == 0)
		ft_r(a, b, 'a', param);
	else if (ft_strcmp(order->str, "rb") == 0)
		ft_r(a, b, 'b', param);
	else if (ft_strcmp(order->str, "rr") == 0)
		ft_r(a, b, 'r', param);
	else if (ft_strcmp(order->str, "pa") == 0)
		ft_pab(a, b, 'a', param);
	else if (ft_strcmp(order->str, "pb") == 0)
		ft_pab(a, b, 'b', param);
	else if (ft_strcmp(order->str, "rra") == 0)
		ft_rrotate(a, b, 'a', param);
	else if (ft_strcmp(order->str, "rrb") == 0)
		ft_rrotate(a, b, 'b', param);
	else if (ft_strcmp(order->str, "rrr") == 0)
		ft_rrotate(a, b, 'r', param);
	else if (ft_strcmp(order->str, "sa") == 0)
		ft_sab(a, b, 'a', param);
	else if (ft_strcmp(order->str, "sb") == 0)
		ft_sab(b, a, 'b', param);
	else
		return (0);
	return (1);
}

int		checker_check(char **args)
{
	int			i;
	int			j;
	long int	max;
	int			negative;
	char		*nb;

	i = -1;
	while (args[++i])
	{
		nb = args[i];
		negative = (nb[0] == '-' && ft_isnumber(nb + 1)) ? 1 : 0;
		if (!ft_isnumber(nb + negative))
			return (1);
		j = -1 + negative;
		max = 0;
		while (args[i][++j])
			max = (max * 10) + (args[i][j] - '0');
		if (max > 2147483647)
			return (1);
		j = i;
		while (args[++j])
			if (ft_strcmp(nb, args[j]) == 0)
				return (1);
	}
	return ((!args[0]) ? 1 : 0);
}

int		check_order(char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		return (0);
	else if (ft_strcmp(str, "rb") == 0)
		return (0);
	else if (ft_strcmp(str, "rr") == 0)
		return (0);
	else if (ft_strcmp(str, "pa") == 0)
		return (0);
	else if (ft_strcmp(str, "pb") == 0)
		return (0);
	else if (ft_strcmp(str, "rra") == 0)
		return (0);
	else if (ft_strcmp(str, "rrb") == 0)
		return (0);
	else if (ft_strcmp(str, "rrr") == 0)
		return (0);
	else if (ft_strcmp(str, "sa") == 0)
		return (0);
	else if (ft_strcmp(str, "sb") == 0)
		return (0);
	else
		return (1);
}

int		ft_isnumber(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		executor(t_list_ps **a, t_list_order *order)
{
	t_list_ps	*b;
	t_param		*param;

	param = param_start(*a, 0);
	param->checker = 1;
	b = NULL;
	while (order)
	{
		if (!order_chooser(a, &b, order, param))
		{
			ft_lst_free(b);
			free(param);
			return (0);
		}
		order = (order)->next;
	}
	if (verif_trif((*a), param) == 0 && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lst_free(b);
	free(param);
	return (1);
}
