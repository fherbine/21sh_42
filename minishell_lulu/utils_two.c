/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:26:27 by llacaze           #+#    #+#             */
/*   Updated: 2018/03/08 15:46:30 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		execve_error(t_info *info)
{
	if (access(info->command, F_OK) == -1)
	{
		write(2, "minishell: command not found: ", 30);
		write(2, info->line_tab[0], ft_strlen(info->line_tab[0]));
		write(2, "\n", 1);
		exit(1);
	}
	if (access(info->command, X_OK) == -1)
	{
		write(2, "minishell: permission denied: ", 30);
		write(2, info->line_tab[0], ft_strlen(info->line_tab[0]));
		write(2, "\n", 1);
		exit(1);
	}
	else if (info->line_tab[0] != NULL &&
		execve(info->command, info->line_tab, info->env) == -1)
	{
		write(2, "minishell: command not found: ", 30);
		write(2, info->line_tab[0], ft_strlen(info->line_tab[0]));
		write(2, "\n", 1);
		exit(1);
	}
}

void		exec_cmd(t_info *info)
{
	int		i;
	char	*tmp;
	char	buf[4096];

	i = 6;
	tmp = NULL;
	while (42)
	{
		tmp = getcwd(buf, 4096);
		ft_putstr("\033[0;32m[\033[0m\033[0;34m*");
		ft_putstr(tmp);
		ft_putstr("]*\033[0m\xe2\x86\x92\e[31m\xe2\x98\x85\033[0m ");
		signal(SIGINT, sig_hand_emp);
		if (get_next_line(0, &info->line) <= 0)
			exit(EXIT_FAILURE);
		else
			exe(info, i);
		i++;
	}
}

int			str_is_ascii(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isascii(str[i]) == 0)
		{
			exit(EXIT_FAILURE);
			return (-1);
		}
		else
			i++;
	}
	return (0);
}
