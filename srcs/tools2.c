/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:12:21 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/13 13:45:47 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rinit(t_list *l)
{
	int	i;

	i = 1;
	while (l)
	{
		l->i = i++;
		l = l->next;
	}
}

int	ft_issorted(t_list *a, t_list *b)
{
	int	n;

	n = a->n;
	a = a->next;
	while (a)
	{
		if (n > a->n || b)
			return (0);
		n = a->n;
		a = a->next;
	}
	return (1);
}
