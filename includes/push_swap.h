/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:59:49 by maduhoux          #+#    #+#             */
/*   Updated: 2018/07/04 00:39:40 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdarg.h>

typedef struct		s_list_a
{
	int				nb;
	struct s_list_a	*next;
}					t_list_ps;

typedef struct		s_param
{
	int				mediane;
	int				mediane_tab[256];
	int				total;
	int				nb_tri;
	int				counta;
	int				countb;
	int				print;
	int				checker;
}					t_param;

int					main(int argc, char **argv);
void				merge(t_list_ps **a, t_list_ps **b, t_param *param);
t_list_ps			*ft_node_new(int nb);
t_list_ps			*ft_lst_add_end(t_list_ps *lst, int nbr);
t_list_ps			*ft_lst_dup(t_list_ps *lst, int nb);
t_list_ps			*sort_list(t_list_ps *lst);
t_param				*param_start(t_list_ps *a, int print);
int					ft_lstlen_ps(t_list_ps *lst);
void				ft_lst_free(t_list_ps *lst);
int					ft_lst_last(t_list_ps *lst);
void				ft_free_arr(char **str);
void				ft_sab(t_list_ps **lst, t_list_ps **b, char c, \
	t_param *param);
void				ft_ss(t_list_ps **a, t_list_ps **b, t_param *param);
void				ft_pab(t_list_ps **a, t_list_ps **b, char c, \
	t_param *param);
void				ft_r(t_list_ps **a, t_list_ps **b, char c, t_param *param);
void				ft_rrotate(t_list_ps **a, t_list_ps **b, char c, \
	t_param *param);
void				sort_two(t_list_ps **a, t_list_ps **b, t_param *param);
void				sort_three(t_list_ps **a, t_list_ps **b, t_param *param);
void				repush_a(t_list_ps **a, t_list_ps **b, t_param *param);
void				keepthree(t_list_ps **a, t_list_ps **b, t_param *param);
void				trithree(t_list_ps **a, t_list_ps **b, t_param *param);
void				dividor(t_list_ps **a, t_list_ps **b, t_param *param);
int					verif_trif(t_list_ps *lst, t_param *param);
int					find_mediane(t_list_ps *lst, int nb);
int					find_mediane_occurence(t_list_ps *lst, t_param *param, \
	char c);
int					check_max_down(t_list_ps *lst, int i);
int					find_min(t_list_ps *lst);
int					find_max(t_list_ps *lst);
int					find_pos(t_list_ps *lst, int nb);
void				insert_a(t_list_ps **a, t_list_ps **b, t_param *param);
void				insert_b(t_list_ps **a, t_list_ps **b, t_param *param);
void				ft_print_lst(t_list_ps *lsta, t_list_ps *lstb, \
	t_param *param);
int					ft_mainps_solo(char **argv);
int					ft_mainps_multiple(char **argv);
void				ft_exit(int keycode);

#endif
