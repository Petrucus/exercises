#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary
{
	struct binary	*right;
	struct binary	*left;
	char			data[];
}					node;

node	*generator(node *head, int depth)
{
	char	*e;
	size_t	str_len;
	node	*branch;

	e = head->data;
	str_len = strlen(e) + 1;
	if (depth < (int)str_len)
		return (head);
	branch = malloc(sizeof(node) + str_len);
	e = e[depth];
	strcpy(branch->data, e);
	branch->left = generator(head->left, depth - 1);
	branch->right = generator(head->right, depth - 1);
	return (branch);
}

int	main(void)
{
	node	*start;
	char	*name;
	size_t	str_len;

	name = "Archibald";
	str_len = strlen(name) + 1;
	start = malloc(sizeof(node) + str_len);
	strcpy(start->data, name);
	start = generator(start, 5);
}
