
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_list
{
	int				n;
	int			    i;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	char			**str;
	t_list			*a;
	t_list			*b;
}					t_lst;

/************************tools**************************/
int		ft_atoi(char *line, int *i)
{
	long long		num;
	int				k;

	k = -1;
	num = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		k = 0;
		num = num * 10 + (line[*i] - 48);
		if (num >= 2147483647)
			num = 2147483647;
		(*i)++;
	}
	return (num + k);
}
   /*********************list*****************************/
/*t_list		*ft_lstnew(char *name)
{
	t_list	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->i = ft_strdup(name);
	elt->next = NULL;
	return (elt);
}*/

t_list		*ft_lstlast(t_list *lst)
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

int		ft_list(t_list  **data,char **ac)
{
    int i;
	int j;
    t_list  *tmp;
 
    i = 1;
	j = 0;
	(*data) = (t_list*)malloc(sizeof(*tmp));
	(*data)->n = ft_atoi(ac[i], &j);
	(*data)->i = i;
	(*data)->next = NULL;
	if (ac[i][j] != 0)
		return (-1);
    while (ac[++i] && !(j = 0))
    {
		tmp = (t_list*)malloc(sizeof(*tmp));
		tmp->n = ft_atoi(ac[i], &j);
		tmp->i = i;
		tmp->next = NULL;
		if (ac[i][j] != 0)
			return (-1);
		ft_lstadd_back(data, tmp);
    }
	return 1;
}

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
/**********************operations****************************/

void ft_swap(t_list **lst)
{
	t_list *tmp;

	tmp  = *lst;
	(*lst) = tmp->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	ft_rinit(*lst);
}

void ft_rotate(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	*lst = tmp->next;
	tmp->next = NULL;
	ft_rinit(*lst);
}

void	ft_rr(t_list **lst)
{
	t_list *tmp;

	tmp = ft_lstlast(*lst);
	while (tmp != (*lst))
		ft_rotate(lst);
	ft_rinit(*lst);
}

void	ft_push(t_list **a,t_list **b)
{
	t_list *tmp;

	if (*b != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	else
	{
		tmp = *a;
		*a = (*a)->next;
		*b = tmp;
		(*b)->next = NULL;
	}
	ft_rinit(*a);
	ft_rinit(*b);
}


/*************************************************************/
t_list		*ft_getsmlnbr(t_list *l)
{
	t_list *tmp;
	int		i;

	i = __INT_MAX__;
	while (l)
	{
		if (l->n < i)
		{
			i = l->n;
			tmp = l;
		}
		l = l->next;
	}
	return (tmp);
}

t_list		*ft_getbignbr(t_list *l)
{
	t_list *tmp;
	int		i;

	i = 0;
	while (l)
	{
		if (l->n > i)
		{
			i = l->n;
			tmp = l;
		}
		l = l->next;
	}
	return (tmp);
}

int		ft_getibn(int n, t_list *l)
{
	while (l)
	{
		if (l->i == n)
		{
			break ;
		}
		l = l->next;
	}
	return (l->n);
}

int		ft_getlistlen(t_list *l)
{
	return (ft_lstlast(l)->i);
}

char		*find_oper(t_list *data, int *i, int pos, int y)
{
	int len;
	int	x;

	len = ft_getlistlen(data);
	x = pos - (len / 2);
	if (x <= 0)
	{
		*i = pos - 1;
		if (y == 1)
			return strdup("ra");
		else
			return strdup("rb");
	}
	else if (x > 0)
	{
		*i = len - pos + 1;
		if (y == 1)
			return strdup("rra");
		else
			return strdup("rrb");
	}
	return NULL;
}

 /**************************algo******************************/
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
	}
	tmp[len] = NULL;
	return (tmp);
}

void	save_act(t_lst *data, char *str)
{
	int		len;

	len = 0;
	data->str = ft_realloc(data->str);
	while (data->str[len])
		len++;
	data->str[len] = strdup(str);
	data->str[len + 1] = NULL;
}

void	ft_exeac(t_lst *data, char *str)
{
	if (!strncmp(str, "sa", 2))
		ft_swap(&data->a);
	else if (!strncmp(str, "ra", 2))
		ft_rotate(&data->a);
	else if (!strncmp(str, "rra", 3))
		ft_rr(&data->a);
	else if (!strncmp(str, "pa", 2))
		ft_push(&data->a, &data->b);
	if (!strncmp(str, "sb", 2))
		ft_swap(&data->b);
	else if (!strncmp(str, "rb", 2))
		ft_rotate(&data->b);
	else if (!strncmp(str, "rrb", 3))
		ft_rr(&data->b);
	else if (!strncmp(str, "pb", 2))
		ft_push(&data->b, &data->a);
	save_act(data, str);
}

void ft_sort2nbr(t_lst *data)
{
	int		top;
	int		mid;

	top = ft_getibn(1, data->a);
	mid = ft_getibn(2, data->a);
	if (top >= mid)
		ft_exeac(data,"sa");
}

void ft_sort3nbr(t_lst *data)
{
	int		top;
	int		bot;
	int		mid;

	top = ft_getibn(1, data->a);
	mid = ft_getibn(2, data->a);
	bot = ft_getibn(3, data->a);
	if (top > mid && top < bot)
		ft_exeac(data,"sa");
	else if(top < mid && top < bot && bot < mid)
	{
		ft_exeac(data,"sa");
		ft_exeac(data,"ra");
	}
	else if (top > mid && mid < bot && top > bot)
		ft_exeac(data,"ra");
	else if(top > mid && top > bot)
	{
		ft_exeac(data,"sa");
		ft_exeac(data,"rra");
	}
	else if(top < mid && top > bot)
		ft_exeac(data,"rra");
}

void	ft_sort4nbr(t_lst	*data)
{
	int		minpos;
	int		i;
	char	*str;

	minpos = ft_getsmlnbr(data->a)->i;
	str = find_oper(data->a, &i, minpos, 1);
	while (i--)
		ft_exeac(data, str);
	free (str);
	free(str);
	ft_exeac(data, "pa");
	ft_sort3nbr(data);
	ft_exeac(data, "pb");
}

void	ft_printlst(t_list *a)
{
	while (a)
	{
		printf("%d  ::  %d\n",a->n, a->i);
		a = a->next;
	}
}
int		getmidpos(t_list *a, int i)
{
	double	m;
	int		max;
	int 	min;
	int		mid;

	max = ft_getbignbr(a)->n;
	min = ft_getsmlnbr(a)->n;
	mid = max - min;
	m = ((double)get_chunk_size(a) / (double)ft_getlistlen(a));
	max = mid * m;
	return (min + max);
}

int get_pos_closestnum(t_lst *a, int mid, int c)
{
	return 0;
}

/******************************************/

int		get_chunk_size(t_list	*a)
{
	if (ft_getlistlen(a) <= 50)
		return (ft_getlistlen(a) / 2 + 1);
	else if (ft_getlistlen(a) <= 100)
		return (20);
	else if (ft_getlistlen(a) <= 170)
		return (40);
	else
		return (45);
	return 0;
}

void movetopto_b(t_lst	*data)
{
	int mid;
	int	a;
	int i;

	a = get_chunk_size(data->a);
	mid	= getmidpos(data->a, a);
	//ft_printlst(data->a);
	//printf("%d   \n", mid);
	i = -1;
	while (ft_getsmlnbr(data->a)->n < mid )
	{
		if (data->a->n == mid)
			ft_exeac(data, "ra");
		else if (data->a->n < mid)
			ft_exeac(data, "pa");
		else
			ft_exeac(data, "ra");;
	}
}

void movetopto_a(t_lst	*data)
{
	int midpos;
	char	*str;
	int		i;

	while (data->b)
	{
		i = 0;
		midpos = ft_getbignbr(data->b)->i;
		if (midpos == 2)
			ft_exeac(data, "sb");
		else
		{
			str = find_oper(data->b, &i, midpos, 0);
			while (i--)
				ft_exeac(data, str);
			free (str);
		}
		ft_exeac(data, "pb");
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
	while (data->str[++i])
		free (data->str[i]);
	free (data->str);
}
void sortmored5(t_lst	*data)
{
	while (ft_getlistlen(data->a) >= 4)
		movetopto_b(data);
	if (ft_getlistlen(data->a) == 2)
		ft_sort2nbr(data);
	//ft_printlst(data->a);
	//ft_printlst(data->b);
	movetopto_a(data);
}

int		pushswap(char  **ac)
{
	t_lst	data;
	int		len;

	data.b = NULL;
	data.str = NULL;
	if (ft_list(&data.a, ac) < 0)
		perror("error :");
	len = ft_getlistlen(data.a);
	if (len == 3)
		ft_sort3nbr(&data);
	else if (len == 4)
		ft_sort4nbr(&data);
	else
		sortmored5(&data);
	ft_printlst(data.a);
	len = 0;
	while (data.str && data.str[len])
		printf("%s\n", data.str[len++]);
	ft_freeallst(&data);
	return 0;
}

int main(int av,char **ac)
{
    int i;
    int j;
	char **p;
    t_list  *data;

    if (av < 2)
        return 1;
    /*if (ft_list(&data, ac) < 0)
		printf("error\n");*/
	//ft_swap(&data);
	//ft_rr(&data);
	//ft_rotate(&data);
	//ft_exeac(&data,"sa");
	//ft_sort3nbr(&data);
	pushswap(ac);
	// while (1);
}