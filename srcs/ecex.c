/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:17:39 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 17:33:12 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_realloc(char **str)
{
	int		len;
	char	**tmp;

	len = 0;
	if (str == NULL)
		tmp = malloc(sizeof(char **) * 2);
	else
	{
		while (str[len])
			len++;
		tmp = malloc(sizeof(char **) * (len + 2));
		len = -1;
		while (str[++len])
			tmp[len] = str[len];
		free(str);
		str = NULL;
	}
	tmp[len] = NULL;
	return (tmp);
}

void	save_act(t_lst *data, char *str)
{
	int		len;

	len = 0;
	data->str = ft_realloc(data->str);
	while (data->str[len] != NULL)
		len++;
	data->str[len] = strdup(str);
	data->str[len + 1] = NULL;
}

int	get_chunk_size(t_list	*a)
{
	if (ft_getlistlen(a) <= 50)
		return (ft_getlistlen(a) / 2 + 1);
	else if (ft_getlistlen(a) <= 100)
		return (20);
	else if (ft_getlistlen(a) <= 170)
		return (40);
	else
		return (45);
	return (0);
}

void	ft_exeac(t_lst *data, char *str, int i)
{
	if (!strncmp(str, "sa", 2))
		ft_swap(&data->a);
	else if (!strncmp(str, "ra", 2))
		ft_rotate(&data->a);
	else if (!strncmp(str, "rra", 3))
		ft_rr(&data->a);
	else if (!strncmp(str, "pa", 2))
		ft_push(&data->b, &data->a);
	if (!strncmp(str, "sb", 2))
		ft_swap(&data->b);
	else if (!strncmp(str, "rb", 2))
		ft_rotate(&data->b);
	else if (!strncmp(str, "rrb", 3))
		ft_rr(&data->b);
	else if (!strncmp(str, "pb", 2))
		ft_push(&data->a, &data->b);
	else if (!strncmp(str, "rrr", 3))
		ft_rrr(data);
	if (i == 1)
		save_act(data, str);
}

void	ft_sort2nbr(t_lst *data)
{
	int	top;
	int	mid;

	top = ft_getibn(1, data->a);
	mid = ft_getibn(2, data->a);
	if (top >= mid)
		ft_exeac(data, "sa", 1);
}
