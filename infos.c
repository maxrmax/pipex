/*
allowed functions:
	open, close, read, write,
	malloc, free, perror,
	strerror, access, dup, dup2,
	execve, exit, fork, pipe,
	unlink, wait, waitpid

	ft_printf and any equivalent
	YOU coded
*/

// ./pipex file1 cmd1 cmd2 file2
// <file cmd1 | cmd2 > file2

//bonus:
// ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// should behave like
// < file1 cmd1 | cmd2 | ... | cmdn > file2
// char	pipex(void)
// {
// 	return (0);
// }

	// 0. Check arguments
	// 1. Parse arguments
	// 2. Open files
	// 3. Create pipes
	// 4. Fork processes
	// 5. Execute commands
	// 6. Close pipes
	// 7. Close files
	// 8. Wait for children
	// 9. Return status

//init_pipex
//check_args
//parse_cmds
//parse_args
//while cmds
// exec
	// pipe, fork, if child/dup2/execv,else/close
//cleanup

// < infile grep Lorem | cut -b 1-15 > outfile

	// pid = fork();
	// if (pid == -1)
	// {
	// 	perror("fork");
	// 	exit(EXIT_FAILURE);
	// }
	// if (pid == 0)
	// 	printf("child (pid: %d)\n", getpid());
	// else
	// 	printf("parent (pid: %d)\n", getpid());
	// i = 0;
	// while (i < argc)
	// {
	// 	printf("Argument %d: %s\n", i, argv[i]);
	// 	i++;
	// }
/*
(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	t_args	*args;

	args = get_args(argc, argv);
	pipe = init_pipe(args->input_file, args->output_file);
	get_path(pipe, envp);
	fork_child_one(pipe, args->first_command, envp);
	fork_child_two(pipe, args->second_command, envp);
	close_parent(pipe);
	waitpid(pipe->pid_one, NULL, 0);
	waitpid(pipe->pid_two, NULL, 0);
	free_pipe(pipe);
	free(args);
	return (0);
*/
/*
ft_exec()
{
	pipe()
	fork()
	if (child)
	{
		dup2()
		execve()
	}
	else
	{
		close()
	}
}*/