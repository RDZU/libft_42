

#include "libft.h"
# include <stdio.h>
t_list	*ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (*lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list *ft_lstlast_back(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	  return (lst);
}
//void delete()
void del(void *content)
{
    free(content);
}
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	while (* lst != NULL)
	{
		ft_lstdelone(*lst,del);
	}
}

int	ft_lstsize(t_list *lst)
{
	 int	count;

	 count = 0;
	 while (lst != NULL)
	 {
		count++;
		lst->next = lst;
	 }
	 return (count);
}
t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}



void display(t_list *n)
{
    while(n != NULL)
    {
    //La sintaxis *(int *)n->data se utiliza 
    //para convertir el valor del campo data de
    //un puntero a un número entero.
  
        printf("%d \n", *(int *)n->content);
        n = n->next;
    }
}
//void	ft_lstadd_front(t_list **lst, t_list *new);
//int		ft_lstsize(t_list *lst);


int main ()
{
	t_list *head = NULL;
	int a = 1337;
	void *pta = &a;
	t_list *node1 = ft_lstnew(pta);
	
	head = node1;
	
	display(head);
}
