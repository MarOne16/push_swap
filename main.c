
#include "pushswap.h"
#include<string.h>

int checknbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		// printf("%c",str[i]);
		if ((str[i] < '0' || str[i] > '9' ) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	checkrepeat(t_list	**ls)
{
	t_list	*ls2;
	t_list	*rest;
	rest = (*ls);
	while ((*ls)->next)
	{
		ls2 = (*ls)->next;
		while (ls2)
		{
			if ((*ls)->content == ls2->content)
				return (1);
			ls2 = ls2->next;
		}
		(*ls) = (*ls)->next;
	}
	(*ls) = rest;
	return (0);
}

void	forcefree(t_list *a, t_list *b)
{
	while (a != 0)
	{
		free(a);
		a = (a)->next;
	}
	while (b != 0)
	{
		free(b);
		b = (b)->next;
	}
}

int binarysize(int decimal)
{
    int digits = 0;
    while (decimal > 0)
    {
        decimal >>= 1;
        digits++;
    }
    return digits;
}

char* decimal_to_binary(int decimal, int digits)
{
	char* binary = malloc((digits + 1) * sizeof(char));
	int index = digits - 1;
	while (index >= 0)
	{
		binary[index] = (decimal & 1) + '0';
		decimal >>= 1;
		index--;
	}
	binary[digits] = '\0';
	return binary;
}

int lstbinarysize(t_list **a)
{
	t_list	*rest;
	int i;

	i = 0;
	rest = (*a);
	while ((*a))
	{
		if (binarysize((*a)->index) > i)
			i = binarysize((*a)->index);
		(*a) = (*a)->next;
	}
	(*a) = rest;
	printf("[%d]\n",i);
	return (i);
}

void lstbinary(t_list **a)
{
	t_list	*rest_a;
	int	size;

	rest_a = (*a);
	size = lstbinarysize(a);
	while ((*a))
	{
		(*a)->d  = decimal_to_binary((*a)->index , size);
		(*a)=(*a)->next;
	}
	*a = rest_a;
}

void bubble_sort(t_list** head) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    t_list* current = *head;
    while (current->next != NULL) {
      if (current->content > current->next->content) {
        int temp = current->content;
        current->content = current->next->content;
        current->next->content = temp;
        sorted = 0;
      }
      current = current->next;
    }
  }
}

t_list *clonelst(char **argv)
{
	int		i;
	t_list	*a;

	i = 0;
	a = NULL;
	while (argv[++i])
	{
		int z = atoi(argv[i]);
		t_list *ls =ft_lstnew(z,i , 0);
		ft_lstadd_back(&a, ls);
	}
	bubble_sort(&a);
	return(a);
}

void indexin(t_list **a , t_list **c)
{
	t_list *rest;
	t_list	*rest_a;
	rest_a = (*a);
	while ((*a))
	{
		rest = (*c);
		while (rest)
		{
			if ((*a)->content == rest->content)
				(*a)->index = rest->index;
			rest = rest->next;
		}
		*a = (*a)->next;
	}
	*a = rest_a;
}

int main(int argc, char *argv[])
{
	int		i;
	int		x = 0;
	t_list	*a;
	t_list	*b;
	t_list	*clone;

	i = 0;
	a = NULL;
	b = NULL;
	while (argv[++i])
	{
		if (!checknbr(argv[i]))
		{
			printf("wa la!"); 
			return(0);
		}
			int z = atoi(argv[i]);
			// char *d = decimal_to_binary(z , 3);
			t_list *ls =ft_lstnew(z,i ,0);
			ft_lstadd_back(&a, ls);
	}
	// checkrepeat(&a); TODO if true break
	clone = clonelst(argv);
	indexin(&a,&clone);
	lstbinary(&a);
	// printf("%c\n",a->d[1]);
	// int bit_val = 8;
	// t_list *tmp = a;
	// while (--bit_val)
	// {
	// 	tmp = a;
	// 	while (tmp && tmp->next && tmp->d && bit_val >= 0)
	// 	{
	// 		if(tmp->d[bit_val] == '1')
	// 			printf("[sa]\n");
	// 		else
	// 		{
	// 			printf("[pb]\n");
	// 		}
	// 		tmp = tmp->next;
	// 	}
	// }
	while (a)
	{
		printf("a[%d]=%s->%d\n",a->index,a->d,a->content);
		a = a->next;
	}
	while (b)
	{
		printf("b[%d]=%s->%d\n",b->index,b->d,b->content);
		b = b->next;
	}
	// forcefree(a,b);
}
