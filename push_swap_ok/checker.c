
#include "push_swap.h"


int	ft_issorted(t_list *a)
{
	int		n;

	n = a->n;
	a = a->next;
	while (a)
	{
		if (n > a->n)
			return (0);
		n = a->n;
		a = a->next;
	}
	return (1);
}

int		ft_cheker(t_lst	*data, char **ac)
{
	int		i;
	t_lst	data1;

	i = -1;
	data1.a = NULL;
	data1.b = NULL;
	if (ft_list(&data1.a , ac) < 0)
	{
		perror("error :");
		exit(0);
	}
	while (data->str && data->str[++i])
		ft_exeac(&data1, data->str[i], 0);
	if (ft_issorted(data1.a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int main(int ac, char **av)
{
    t_list data;

    if (ac == 1)
        write(1, "error\n", 6);
    ft_cheker(&data, av);
}