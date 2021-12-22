#ifndef PIPE_H
# define PIPE_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_node
{
	void 			*content;
	struct s_node 	*next;
}	t_node;

typedef struct s_pipe
{
	int 	argc;
	char 	**argv;
	char 	**envp;
	t_node	*pipe;
	t_node 	*node;
	t_node	*path;
}	t_pipe;

#endif