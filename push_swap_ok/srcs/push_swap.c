/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaouil <otaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:19:55 by otaouil           #+#    #+#             */
/*   Updated: 2021/07/11 20:20:07 by otaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		pushswap(char  **ac)
{
	t_lst	data;
	int		len;

	data.b = NULL;
	data.str = NULL;
	if (ft_list(&data.a, ac) < 0)
	{
		write(1, "error", 5);
		exit(0);
	}
	len = ft_getlistlen(data.a);
	if (len == 3)
		ft_sort3nbr(&data);
	else if (len == 4)
		ft_sort4nbr(&data);
	else
		sortmored5(&data);
	len = -1;
	while (data.str && data.str[++len])
	{
		write(1, data.str[len], strlen(data.str[len]));
		write(1, "\n", 1);
	}
	ft_cheker(&data, ac);
	ft_freeallst(&data);
	return 0;
}


int main(int av,char **ac)
{
    int i;
    int j;
	char **p;
    t_list  data;

    if (av < 2)
        return 1;
    /*if (ft_list(&data.a, ac) < 0)
	{
		perror("error :");
		exit(0);
	}*/
	//ft_swap(&data);
	//ft_rr(&data);
	//ft_rotate(&data);
	//ft_exeac(&data,"sa");
	//ft_sort3nbr(&data);
	pushswap(ac);
	// while (1);
}