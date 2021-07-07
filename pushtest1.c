
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

char		*find_oper(t_list *data, int *i, int pos, int j)
{
	int len;
	int	x;

	if (j == 1)
		len = ft_getlistlen(data);
	x = pos - (len / 2);
	if (x <= 0)
	{
		*i = pos - 1;
		return strdup("ra");
	}
	else if (x > 0)
	{
		*i = len - pos + 1;
		return strdup("rra");
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

void ft_sort3nbr(t_lst *data)
{
	int		top;
	int		bot;
	int		mid;

	top = ft_getibn(1, data->a);
	mid = ft_getibn(2, data->a);
	bot = ft_getibn(3, data->a);
	//printf("%d  ::  %d  :: %d\n",top, mid, bot);
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
	free(str);
	ft_exeac(data, "pa");
	ft_sort3nbr(data);
	ft_exeac(data, "pb");
	//ft_exeac(a,b,"pa");
}

int		getmidpos(t_list *a, int i)
{
	t_list	*x;

	x = a;
	while (a && i)
	{
		if (x->n < a->n)
			x = a;
		a = a->next;
		i--;
	}
	return (x->n);
}

int get_pos_closestnum(t_lst *a, int mid, int c)
{

}

/******************************************/

int		get_chunk_size(t_list	*a)
{
	if (ft_getlistlen(a) <= 50)
		return (ft_getlistlen(a) / 2 + 1);
	return 0;
}

void sortmored5(t_lst	*data)
{
	int big;
	int	a;
	int e;

	big	= getmidpos(data->a, get_chunk_size(data->a));
	while (ft_getlistlen(data->a) >= 2)
	{
		
	}
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
	while (data.a)
	{
		printf("%d  ::  %d\n",data.a->n, data.a->i);
		data.a = data.a->next;
	}
	len = 0;
	while (data.str)
		printf("%s\n", data.str[len++]);
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
}