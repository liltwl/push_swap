/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:11:10 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/12 16:47:02 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str, int *i)
{
	int		n;
	long	m;
	char	*p;

	p = (char *)str;
	n = 1;
	m = 0;
	if (p[*i] == '-' || p[*i] == '+')
	{
		if (p[(*i)++] == '-')
			n *= -1;
	}
	while (p[*i] && p[*i] >= '0' && p[*i] <= '9')
	{
		m = (m * 10) + (p[(*i)++] - 48);
		if (m > 2147483648 && n == -1)
			return (0);
		else if (m > 2147483647 && n == 1)
			return (-1);
	}
	return (m *= n);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

int	ft_check(t_list *data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (data)
	{
		tmp = data->next;
		while (tmp)
		{
			if (tmp->n == data->n)
				return (-1);
			tmp = tmp->next;
		}
		data = data->next;
	}
	return (1);
}

int	ft_list(t_list **data, char **ac)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	(*data) = (t_list *)malloc(sizeof(*tmp));
	(*data)->n = ft_atoi(ac[i], &j);
	(*data)->i = i;
	(*data)->next = NULL;
	if (ac[i][j] != 0)
		return (-1);
	while (ac[++i])
	{
		j = 0;
		tmp = (t_list *)malloc(sizeof(*tmp));
		tmp->n = ft_atoi(ac[i], &j);
		tmp->i = i;
		tmp->next = NULL;
		if (ac[i][j] != 0)
			return (-1);
		ft_lstadd_back(data, tmp);
	}
	return (ft_check(*data));
}
