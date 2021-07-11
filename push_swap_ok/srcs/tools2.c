/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:12:21 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/11 20:12:39 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rinit(t_list *l)
{
	int i;

	i = 1;
	while (l)
	{
		l->i = i++;
		l = l->next;
	}
}
