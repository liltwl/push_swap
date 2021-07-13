/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:18:16 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 17:09:40 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort3nbr(t_lst *data)
{
	int	top;
	int	bot;
	int	mid;

	top = ft_getibn(1, data->a);
	mid = ft_getibn(2, data->a);
	bot = ft_getibn(3, data->a);
	if (top > mid && top < bot)
		ft_exeac(data, "sa", 1);
	else if (top < mid && top < bot && bot < mid)
	{
		ft_exeac(data, "sa", 1);
		ft_exeac(data, "ra", 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ft_exeac(data, "ra", 1);
	else if (top > mid && top > bot)
	{
		ft_exeac(data, "sa", 1);
		ft_exeac(data, "rra", 1);
	}
	else if (top < mid && top > bot)
		ft_exeac(data, "rra", 1);
}

void	ft_sort4nbr(t_lst *data)
{
	int		minpos;
	int		i;
	char	*str;

	minpos = ft_getsmlnbr(data->a)->i;
	str = find_oper(data->a, &i, minpos, 1);
	while (i--)
		ft_exeac(data, str, 1);
	free (str);
	ft_exeac(data, "pb", 1);
	ft_sort3nbr(data);
	ft_exeac(data, "pa", 1);
}

void	ft_printlst(t_list *a)
{
	while (a)
	{
		printf("%d  ::  %d\n", a->n, a->i);
		a = a->next;
	}
}

int	getmidpos(t_list *a)
{
	double	m;
	int		max;
	int		min;
	int		mid;

	max = ft_getbignbr(a)->n;
	min = ft_getsmlnbr(a)->n;
	mid = max - min;
	m = ((double)get_chunk_size(a)) / (double)ft_getlistlen(a);
	max = mid * m;
	return (min + max);
}

int	get_closestnum(t_lst *data, int c)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = data->a;
	i = ft_lstlast(data->a)->n;
	j = ft_lstlast(data->a)->i;
	while (tmp)
	{
		if (c > i && c < tmp->n)
		{
			return (tmp->i);
		}
		i = tmp->n;
		tmp = tmp->next;
	}
	return (ft_lstlast(data->a)->i);
}
