/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:16:52 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 16:43:59 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_getsmlnbr(t_list *l)
{
	t_list	*tmp;
	int		i;

	i = __INT_MAX__;
	while (l)
	{
		if (l->n < i)
		{
			i = l->n;
			tmp = l;
		}
		l = l->next;
	}
	return (tmp);
}

t_list	*ft_getbignbr(t_list *l)
{
	t_list	*tmp;
	int		i;

	i = __INT_MAX__ * -1;
	while (l)
	{
		if (l->n > i)
		{
			i = l->n;
			tmp = l;
		}
		l = l->next;
	}
	return (tmp);
}

int	ft_getibn(int n, t_list *l)
{
	while (l)
	{
		if (l->i == n)
		{
			break ;
		}
		l = l->next;
	}
	return (l->n);
}

int	ft_getlistlen(t_list *l)
{
	return (ft_lstlast(l)->i);
}

char	*find_oper(t_list *data, int *i, int pos, int y)
{
	int	len;
	int	x;

	len = ft_getlistlen(data);
	x = pos - (len / 2);
	if (x <= 0)
	{
		*i = pos - 1;
		if (y == 1)
			return (strdup("ra"));
		else
			return (strdup("rb"));
	}
	else if (x > 0)
	{
		*i = len - pos + 1;
		if (y == 1)
			return (strdup("rra"));
		else
			return (strdup("rrb"));
	}
	return (NULL);
}
