/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:18:50 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 16:48:58 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	movetopto_b(t_lst *data)
{
	int	mid;
	int	a;
	int	i;

	a = get_chunk_size(data->a);
	mid = getmidpos(data->a);
	i = -1;
	while (ft_getsmlnbr(data->a)->n < mid)
	{
		if (data->a->n == mid)
			ft_exeac(data, "ra", 1);
		else if (data->a->n < mid)
			ft_exeac(data, "pb", 1);
		else
			ft_exeac(data, "ra", 1);
	}
}

void	movetopto_a(t_lst	*data)
{
	int		midpos;
	char	*str;
	int		i;

	while (data->b)
	{
		i = 0;
		midpos = ft_getbignbr(data->b)->i;
		if (midpos == 2)
			ft_exeac(data, "sb", 1);
		else if (midpos > 2)
		{
			str = find_oper(data->b, &i, midpos, 0);
			while (i--)
				ft_exeac(data, str, 1);
			free (str);
		}
		ft_exeac(data, "pa", 1);
	}
}

void	ft_freeallst(t_lst *data)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (data->a)
	{
		tmp = data->a;
		data->a = data->a->next;
		free (tmp);
	}
	while (data->b)
	{
		tmp = data->b;
		data->b = data->b->next;
		free (tmp);
	}
	while (data->str && data->str[++i])
		free (data->str[i]);
	free (data->str);
}

void	sortmored5(t_lst	*data)
{
	while (ft_getlistlen(data->a) > 4)
		movetopto_b(data);
	if (ft_getlistlen(data->a) == 2)
		ft_sort2nbr(data);
	else if (ft_getlistlen(data->a) == 4)
		ft_sort4nbr(data);
	else if (ft_getlistlen(data->a) == 3)
		ft_sort3nbr(data);
	movetopto_a(data);
}
