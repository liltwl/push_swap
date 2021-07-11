/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:14:45 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/11 20:15:15 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(t_list **lst)
{
	t_list *tmp;

	tmp  = *lst;
	(*lst) = tmp->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	ft_rinit(*lst);
}

void ft_rotate(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	*lst = tmp->next;
	tmp->next = NULL;
	ft_rinit(*lst);
}

void	ft_rr(t_list **lst)
{
	t_list *tmp;

	tmp = ft_lstlast(*lst);
	while (tmp != (*lst))
		ft_rotate(lst);
	ft_rinit(*lst);
}

void	ft_push(t_list **a,t_list **b)
{
	t_list *tmp;

	if (*b != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	else
	{
		tmp = *a;
		*a = (*a)->next;
		*b = tmp;
		(*b)->next = NULL;
	}
	ft_rinit(*a);
	ft_rinit(*b);
}

void	ft_rrr(t_lst *data)
{
	ft_rr(&data->a);
	ft_rr(&data->b);
	ft_rinit(data->a);
	ft_rinit(data->b);
}
