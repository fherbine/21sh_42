/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:57:56 by llacaze           #+#    #+#             */
/*   Updated: 2018/05/09 18:05:04 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
 
int	 simple_redir_right(char **av)
{
  int   fd;
  char *str;
 
  if (av[2] == NULL)
	exit(EXIT_FAILURE);
  if (av[2][0] == '>')
	{
		if ((fd = open(av[3], O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
			strerror(errno);
	}
  dup2(fd, 1);
  return (0);
}
 
int	 double_redir_right(char **av)
{
  int   fd;
 
	if ((fd = open(av[1],O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR
				 | S_IRGRP | S_IROTH)) == -1)
		strerror(errno);
	dup2(fd, 1);
	close(fd);
	return (0);
}
 
int	 main(int ac, char **av)
{
  (void)ac;
  simple_redir_right(av);
}