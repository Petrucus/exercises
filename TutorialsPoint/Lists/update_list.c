#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 6

struct				node
{
	int				data;
	struct node		*next;
};

typedef struct node	node;

node	*insert(node *head, int data)
{
	node	*link;

	link = calloc(1, sizeof(node));
	if (!link)
		return (NULL);
	link->data = data;
	link->next = head;
	return (link);
}

void	display(const node *head)
{
	puts("\n=== LINKED LIST ===\n");
	while (head->next)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("%d\n", head->data);
}

void	update_data(node *head, int current, int future)
{
	while (head->next)
	{
		if (head->data == current)
			head->data = future;
		head = head->next;
	}
	if (head->data == current)
		head->data = future;
}

void	remove_link_once(node **head, int *values, int values_size)
{
	node	*temp_store;
	int		iter;
	node	*head_start;

	temp_store = NULL;
	iter = 0;
	head_start = *head;
	while ((*head)->next)
	{
		iter = 0;
		while (iter < values_size)
		{
			if ((*head)->next->data == values[iter])
			{
				temp_store = (*head)->next;
				(*head)->next = (*head)->next->next;
				free(temp_store);
				values++;
				values_size--;
			}
			iter++;
		}
		(*head) = (*head)->next;
	}
	*head = head_start;
	iter = 0;
	while (iter < values_size)
	{
		if ((*head)->data == values[iter])
		{
			temp_store = (*head);
			*head = (*head)->next;
			free(temp_store);
		}
		iter++;
	}
}

int	main(void)
{
	node	*head;
	int		array[ARRAY_SIZE] = {10, 20, 30, 1, 40, 56};
	int		values_to_remove[3] = {20, 1, 56};
	int		iter;

	head = NULL;
	iter = 0;
	while (iter < ARRAY_SIZE)
		head = insert(head, array[iter++]);
	display(head);
	update_data(head, 40, 44);
	display(head);
	remove_link_once(&head, values_to_remove, 3);
	display(head);
	return (0);
}
