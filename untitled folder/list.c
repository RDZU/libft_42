
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
	void  *content;
	//estructura auto-referenciada
	struct s_list *next;
}t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new_node;
	new_node = (t_list *)malloc(sizeof(t_list));
	if(new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return new_node;
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

void    ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	int la;
	la = 0;

	while (lst != NULL)
	{
		lst = lst->next;
		la++;
	}
	return la;
}

t_list *ft_lstlast(t_list *lst)
{
	while(lst->next != NULL)
	{
		lst = lst->next;
	}
	return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list *p;
  
	if (*lst)
	{
		p = ft_lstlast(*lst);
		p -> next = new;
	}
	else
		*lst = new;
}


void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
void    ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*aux;

	if (!lst || !del)
		return (NULL);
	current = *lst;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		del(aux->content);
		free(aux);
	}
	*lst = (NULL);
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || f)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!lst || new)
		return ;
	
}
void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!lst != NULL)
		return ;
	last = ft_lstlast(lst);
	last->next = new;
}
// void ft_lstclear(t_list **lst, void(*del)(void));

// void ft_lstiter(t_list *lst, void(*f)(void *));

int main()
{
	t_list *head = NULL;  // Start with an empty list
//printf("1 head almacena:  %p\n", head);
  //    printf("1 la direccion de memoria de head:  %p\n", &head);
	// Create a node with initial content
	int a = 1337;
	void *pta = &a;
	t_list *node1 = ft_lstnew(pta);

	// Add node1 to the list (now it becomes the head)
	head = node1;
	//printf(" 2 head almacena:  %p\n", head);
	  //printf(" 2 la direccion de memoria de head:  %p\n", &head);
	// Create another node to be added
	int b = 42;
	void *ptb = &b;
	t_list *node2 = ft_lstnew(ptb);

	// Use ft_lstadd_front to insert node2 at the beginning
	ft_lstadd_front(&head, node2);  // Pass the address of head to modify it

   //head = node2;
   //printf(" 3 head almacena:  %p\n", head);
	 // printf(" 3 la direccion de memoria de head:  %p\n", &head);
	int c = 50;
	void *ptc = &c;
	t_list *node3 = ft_lstnew(ptc);

	// Use ft_lstadd_front to insert node2 at the beginning
	ft_lstadd_front(&head, node3); 
   //ft_lstadd_back(&head,node3);
	// Print the list to verify the insertion
   // printf(" 4 head almacena:  %p\n", head);
 //     printf(" 4 la direccion de memoria de head:  %p\n", &head);

	ft_lstdelone(&head,del_content);
	printf("Contents of the list:\n");
	display(head);
 //   printf("%d",ft_lstsize(head));
	
		//  display(ft_lstlast(head));
	


	// Free the memory to avoid leaks
	free(node1);
	free(node2);
	// free(node3);
	//  printf(" 5 head almacena:  %p\n", head);
	  //printf(" 5 la direccion de memoria de head:  %p\n", &head);
	return 0;
}