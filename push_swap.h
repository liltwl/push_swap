/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:35:08 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 18:11:14 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				n;
	int				i;
	struct s_list	*next;
}					t_list;

typedef struct s_lst
{
	char			**str;
	t_list			*a;
	t_list			*b;
}					t_lst;

int		pushswap(char **ac);
int		ft_cheker(t_lst	*data);
int		ft_issorted(t_list *a, t_list *b);
void	sortmored5(t_lst *data);
void	movetopto_b(t_lst *data);
void	movetopto_a(t_lst *data);
void	ft_freeallst(t_lst *data);
t_list	*ft_getsmlnbr(t_list *l);
t_list	*ft_getbignbr(t_list *l);
int		ft_getibn(int n, t_list *l);
int		ft_getlistlen(t_list *l);
char	*find_oper(t_list *data, int *i, int pos, int y);
char	**ft_realloc(char **str);
void	save_act(t_lst *data, char *str);
int		get_chunk_size(t_list *a);
void	ft_exeac(t_lst *data, char *str, int i);
void	ft_sort2nbr(t_lst *data);
void	ft_sort3nbr(t_lst *data);
void	ft_sort4nbr(t_lst *data);
void	ft_printlst(t_list *a);
int		getmidpos(t_list *a);
int		get_closestnum(t_lst *data, int c);
void	movetopto_b(t_lst *data);
void	movetopto_a(t_lst *data);
int		ft_atoi(const char *str, int *i);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_check(t_list *data);
int		ft_list(t_list **data, char **ac);
void	ft_rinit(t_list *l);
void	ft_swap(t_list **lst);
void	ft_rotate(t_list **lst);
void	ft_rr(t_list **lst);
void	ft_push(t_list **a, t_list **b);
void	ft_rrr(t_lst *data);
int		number_of_words(char *str, char c);
int		word_size(char *str, char c);
void	fill_string(char *str, char *cas, char c);
char	**ft_split(char const *s, char c);
char	**ft_free_split(char **d);
void	ft_closee(int i);

#endif