#ifndef TOOLS_NODE_H
# define TOOLS_NODE_H
# include "tools_common.h"

void 	clear_list(t_node *begin);
void 	append_node(t_node **begin, t_node *append);
t_node 	*set_node(t_node **begin, void *order);
t_node 	*new_node(t_node **node, void* content, size_t size);
t_node 	*get_last(t_node *node);

#endif