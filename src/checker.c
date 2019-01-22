/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:17:19 by maduhoux          #+#    #+#             */
/*   Updated: 2018/07/04 00:30:39 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"
#include <stdio.h>

static void		last_free(t_list_ps **a, t_list_order **order)
{
	ft_lst_free(*a);
	ft_order_free(*order);
}

t_list_order	*ft_in_main(t_list_order **order)
{
	int		i;
	char	*line;

	while ((i = get_next_line(0, &line)) > 0)
	{
		if (check_order(line) == 0)
		{
			if (!(*order = ft_order_add_end(*order, line)))
			{
				free(line);
				ft_exit(-1);
			}
		}
		else
		{
			free(line);
			ft_exit(1);
		}
	}
	free(line);
	return (*order);
}

int				ft_mainck_solo(char **argv)
{
	int				i;
	t_list_ps		*a;
	t_list_order	*order;
	char			**args;

	if (!(args = ft_strsplit(argv[1], ' ')))
		ft_exit(-1);
	if (checker_check(args) == 1)
		ft_exit(1);
	a = NULL;
	i = -1;
	while (args[++i])
		if (!(a = ft_lst_add_end(a, ft_atoi(args[i]))))
			return (1);
	order = NULL;
	order = ft_in_main(&order);
	if (!executor(&a, order))
	{
		last_free(&a, &order);
		ft_free_arr(args);
		return (1);
	}
	ft_free_arr(args);
	last_free(&a, &order);
	return (0);
}

int				ft_mainck_multiple(char **argv)
{
	int				i;
	t_list_ps		*a;
	t_list_order	*order;

	if (checker_check((argv + 1)) == 1)
		ft_exit(1);
	a = NULL;
	i = 0;
	while (argv[++i])
		if (!(a = ft_lst_add_end(a, ft_atoi(argv[i]))))
			ft_exit(-1);
	order = NULL;
	order = ft_in_main(&order);
	if (!executor(&a, order))
	{
		last_free(&a, &order);
		return (1);
	}
	last_free(&a, &order);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc == 2)
			if (ft_mainck_solo(argv) == 1)
				ft_exit(0);
		if (argc > 2)
			if (ft_mainck_multiple(argv) == 1)
				ft_exit(0);
	}
	return (0);
}
