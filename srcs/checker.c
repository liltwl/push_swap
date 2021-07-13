/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:29:14 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/13 13:45:29 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_cheker(t_lst	*data)
{
	int	i;

	i = -1;
	data->b = NULL;
	while (data->str && data->str[++i])
		ft_exeac(data, data->str[i], 0);
	if (ft_issorted(data->a, data->b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freeallst(data);
	return (0);
}

int	ft_isact(char *l)
{
	char	**str;
	int		i;

	i = -1;
	str = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (str[++i])
	{
		if (!strcmp(str[i], l))
		{
			ft_free_split(str);
			return (0);
		}
	}
	ft_free_split(str);
	return (1);
}

void	ft_close(int i)
{
	write(1, "error\n", 6);
	exit(i);
}

int	main(int ac, char **av)
{
	t_lst	data;
	char	*lin;

	data.a = NULL;
	data.str = NULL;
	if (ac == 1)
		return (0);
	if (ft_list(&data.a, av) < 0)
		ft_close(255);
	while (get_next_line(0, &lin))
	{
		if (ft_isact(lin) == 1)
			ft_close(1);
		save_act(&data, lin);
		free (lin);
	}
	return (ft_cheker(&data));
}
