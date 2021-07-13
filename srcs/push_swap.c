/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:19:55 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/13 13:49:03 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_closee(int i)
{
	write(1, "error", 5);
	exit(i);
}

int	pushswap(char **ac)
{
	t_lst	data;
	int		len;

	data.b = NULL;
	data.str = NULL;
	if (ft_list(&data.a, ac) < 0)
		ft_closee(1);
	if (ft_issorted(data.a, data.b))
		return (0);
	if (ft_getlistlen(data.a) == 2)
		ft_sort2nbr(&data);
	else if (ft_getlistlen(data.a) == 3)
		ft_sort3nbr(&data);
	else if (ft_getlistlen(data.a) == 4)
		ft_sort4nbr(&data);
	else
		sortmored5(&data);
	len = -1;
	while (data.str && data.str[++len])
	{
		write(1, data.str[len], strlen(data.str[len]));
		write(1, "\n", 1);
	}
	ft_freeallst(&data);
	return (0);
}

int	main(int av, char **ac)
{
	if (av < 2)
		return (0);
	return (pushswap(ac));
}
