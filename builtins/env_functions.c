/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:14:24 by llacaze           #+#    #+#             */
/*   Updated: 2018/05/09 16:40:23 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/21sh.h"

void		print_env_line(t_info *info, char *elem)
{
	char	**str;
	int		line;

	line = 0;
	if (info->line_tab[2] == NULL)
	{
		write(2, "env: option requires an argument -- u\n", 38);
		return ;
	}
	while (info->env[line])
	{
		str = ft_strsplit(info->env[line], '=');
		if (ft_strcmp(str[0], elem) != 0)
		{
			ft_putstr(info->env[line]);
			write(1, "\n", 1);
		}
		line++;
	}
}

char		*change_line(char *str, char *elem, char *new_elem)
{
	char	*tmp;

	free(str);
	str = ft_strdup(elem);
	tmp = str;
	str = ft_strjoin(elem, "=");
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, new_elem);
	free(tmp);
	return (str);
}

t_info		*change_line_env(t_info *info, char *elem, char *new_elem)
{
	char	**str;
	int		line;

	line = 0;
	while (info->env[line])
	{
		str = ft_strsplit(info->env[line], '=');
		if (ft_strcmp(str[0], elem) == 0)
		{
			info->env[line] = change_line(info->env[line], elem, new_elem);
			free_tab(str);
			info->repl = 1;
			return (info);
		}
		free_tab(str);
		line++;
	}
	info->repl = 0;
	return (info);
}