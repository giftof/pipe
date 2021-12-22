#include "tools_node.h"

void clear_list(t_node *begin)
{
	t_node *temp;

	temp = begin;
	while(begin)
	{
		temp = temp->next;
		free(begin->content);
		free(begin);
		begin = temp;
	}
}

void append_node(t_node **begin, t_node *append)
{
	t_node *last;

	last = get_last(*begin);
	if (last)
		last->next = append;
	else
		*begin = append;
}

t_node *set_node(t_node **begin, void *content)
{
	t_node *current;

	current = 0;
	if (content)
	{
		if (new_node(&current, content, sizeof(t_node)))
			append_node(begin, current);
	}
	return current;
}

t_node *new_node(t_node **new, void *content, size_t size)
{
	t_node *node;

	node = malloc(size);
	*new = node;
	if (new)
	{
		(*new)->content = content;
		(*new)->next = 0;
	}
	else
		free(content);
	return node;
}

t_node *get_last(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return node;
}