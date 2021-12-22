#include "tools_common.h"
#include "tools_node.h"

void *set_default(t_pipe *p, int argc, char **argv, char **envp)
{
	t_node	*node;
	int		index;

	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
	p->node = 0;
	p->pipe = 0;
	index = 0;
	while((++index) < argc)
	{
		if (!set_node(&p->node, str_dup(argv[index])))
		{
			clear_list(p->node);
			p->node = 0;
			break;
		}
	}
	return (pipe->node);
}

void *set_pipe(t_pipe *p)
{
	int 	index;
	int		fd[2];
	t_node 	*node;
	int		*content;

	index = 1;
	while((++index + 2) < p->argc)
	{
		if (pipe(fd) < 0)
			return (0);
		content = malloc(sizeof(int) * 3);
		if (content)
		{
			content[0] = fd[0];
			content[1] = fd[1];
			if (!set_node(&p->pipe, (void *)content))
			{
				clear_list(p->pipe);
				p->pipe = 0;
				break;
			}
		}
	}
	return (p->pipe);
}

void *set_path(t_pipe *p)
{
	int index;

	index = 0;
	while(str_cmp(p->envp[index])
	{
		
	}
}

void clear_data(t_pipe *pipe)
{
	clear_list(pipe->node);
	clear_list(pipe->pipe);
}

// TEST BEGIN
void PRINT_DATA(t_node *node)
{
	while (node)
	{
		printf("content = %s\n", (char *)node->content);
		node = node->next;
	}
}

void PRINT_FD(t_node *node)
{
	while (node)
	{
		printf("fds = [%d], [%d]\n", ((int *)node->content)[0], ((int *)node->content)[1]);
		node = node->next;
	}
}
// TEST END

void exec(t_pipe *pipe)
{
	pid pid;
	
	pid = fork();
	if (!pid)
	{
		
		execve()
	}
}

int execute(t_pipe *pipe)
{
	int fd[2];

	// printf("begin execute\n");
	// printf("%s\n", (char *)pipe->node->content);
	// printf("%s\n", (char *)get_last(pipe->node)->content);
	fd[0] = open((char *)pipe->node->content, O_RDONLY);
	fd[1] = open((char *)get_last(pipe->node)->content, 0x601);
	// printf("%d, %d\n", fd[0], fd[1]);

	if (0 < fd[0] && 0 < fd[1])
	{
		if (0 < dup2(((int *)pipe->pipe->content)[0], fd[0])
		 && 0 < dup2(((int *)pipe->pipe->content)[1], fd[1]))
		{
			close(fd[0]);
			close(fd[1]);
			printf("hello~~~\n"); // execute
		}
	}
	close(((int *)pipe->pipe->content)[0]);
	close(((int *)pipe->pipe->content)[1]);
	return (1);
}

// void print_argv(char **argv)
// {
// 	int index;

// 	index = 0;
// 	while(*argv[index])
// 	{
// 		printf("[%d] str = [%s]\n", index, argv[index]);
// 		++index;
// 	}
// }


int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe;
	int		result;

	print_argv(argv);

	result = 0;
	if (argc < 5 
		|| !set_default(&pipe, argc, argv, envp)
		|| !set_pipe(&pipe)
		|| execute(&pipe))
		result = 1;
	
	// printf("argc = [%d]\n", argc);
	// PRINT_DATA(pipe.node);
	// PRINT_FD(pipe.pipe);
	clear_data(&pipe);
	return (result);
}
