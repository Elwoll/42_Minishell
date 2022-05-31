/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/31 19:04:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 * Default Library
*/

# include "minishell.h"
# include "utils.h"

/*
 * Authorized Functions Library
*/

# include <stdio.h>		/* printf, strerror, perror, readline */
# include <stdlib.h>		/* malloc, free, exit, getenv */
# include <unistd.h>		/* access, getcwd, chdir, unlink, pipe's, tty's*/
# include <fcntl.h>		/* open */
# include <sys/types.h>		/* read | wait, waitpid, wait3, wait4 */
# include <sys/uio.h>		/* read */
# include <sys/wait.h>		/* wait, waitpid, wait3, wait4 */
# include <sys/time.h>		/* wait, waitpid, wait3, wait4 */
# include <sys/resource.h>	/* wait, waitpid, wait3, wait4 */
# include <signal.h>		/* signal, sigaction, sigemptyset, sigaddset, kill */
# include <sys/stat.h>		/* stat, lstat, fstat */
# include <dirent.h>		/* opendir, readdir, closedir */
# include <sys/ioctl.h>		/* ioctl */
# include <termios.h>		/* tcsetattr, tcgetattr */
# include <curses.h>		/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
# include <term.h>		/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */

/*
 * Readline library
*/

# include <readline/readline.h>
# include <readline/history.h>

/*
 * Error And Messages Handling
*/

# define N_ARGS "\e[1;31mError, this binary doesn't accept arguments\n\e[0m"
# define ALLOC "\e[1;31mError, dynamic memory allocation failed\n\e[0m"
# define Q_ERROR "\e[1;31mQuote not closed\n\e[0m"

/*
 * Global Variables
*/

extern int	g_exit_status;

/*
 * Structures
*/

typedef struct s_echo
{
	char	*cmd;
}				t_echo;

typedef struct s_main
{
	char	*prompt;
	char	*input;
	char	*res;
}				t_main;

/*
 * Functions Declaration
*/

void	prompt_creation(t_main *main);

/*
 * Builts-Ins
*/

void	b_echo(t_main *main, char **input);
void	b_exit();
void	b_pwd();
void	b_unset();

/*
 * Parsing
*/

void	simple_quote(t_main *main);
int		n_quote(t_main *main);
void	memory_flush(char **tmp, char ***split);

/*
 * Memory Functions
*/

void	alloc_check(void *ptr);

#endif
