/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:41:02 by maduhoux          #+#    #+#             */
/*   Updated: 2018/07/04 00:40:21 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include <stdio.h>

static void	last_free(t_list_ps **a, char **args, t_param *param)
{
	ft_lst_free(*a);
	ft_free_arr(args);
	free(param);
}

void		merge(t_list_ps **a, t_list_ps **b, t_param *param)
{
	if (verif_trif(*a, param) == 0)
		return ;
	if (param->counta == 2)
		sort_two(a, b, param);
	if (param->counta <= 3)
		sort_three(a, b, param);
	else if (param->counta > 20)
	{
		dividor(a, b, param);
		sort_three(a, b, param);
		while (param->countb > 20)
		{
			verif_trif(*a, param);
			repush_a(a, b, param);
			keepthree(a, b, param);
			trithree(a, b, param);
		}
		insert_b(a, b, param);
	}
	else
		insert_a(a, b, param);
}

int			ft_mainps_solo(char **argv)
{
	int			i;
	t_list_ps	*a;
	t_list_ps	*b;
	t_param		*param;
	char		**args;

	a = NULL;
	b = NULL;
	i = (ft_strcmp(argv[1], "-a") == 0 ? 2 : 1);
	if (!(args = ft_strsplit(argv[i], ' ')))
		return (1);
	if (checker_check(args) == 1)
		return (1);
	i = -1;
	while (args[++i])
		a = ft_lst_add_end(a, ft_atoi(args[i]));
	i = (ft_strcmp(argv[1], "-a") == 0) ? 1 : 0;
	if (!(param = param_start(a, i)))
		return (1);
	merge(&a, &b, param);
	verif_trif(a, param);
	if (param->print == 1)
		ft_print_lst(a, b, param);
	last_free(&a, args, param);
	return (0);
}

int			ft_mainps_multiple(char **argv)
{
	int			i;
	t_list_ps	*a;
	t_list_ps	*b;
	t_param		*param;

	a = NULL;
	b = NULL;
	i = (ft_strcmp(argv[1], "-a") == 0 ? 1 : 0);
	if (checker_check((argv + i + 1)) == 1)
		return (1);
	while (argv[++i])
		if (!(a = ft_lst_add_end(a, ft_atoi(argv[i]))))
			return (1);
	i = (ft_strcmp(argv[1], "-a") == 0) ? 1 : 0;
	if (!(param = param_start(a, i)))
		return (1);
	merge(&a, &b, param);
	verif_trif(a, param);
	if (param->print == 1)
		ft_print_lst(a, b, param);
	ft_lst_free(a);
	free(param);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-a") == 0)
			argc--;
		if (argc == 2)
		{
			if (ft_mainps_solo(argv) == 1)
			{
				ft_putstr("Error\n");
				return (1);
			}
		}
		if (argc > 2)
		{
			if (ft_mainps_multiple(argv) == 1)
			{
				ft_putstr("Error\n");
				return (1);
			}
		}
	}
	return (0);
}
