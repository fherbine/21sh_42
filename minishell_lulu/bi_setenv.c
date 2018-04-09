/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:06:35 by llacaze           #+#    #+#             */
/*   Updated: 2018/03/08 15:43:22 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*new_line(char *str, char *elem, char *new_elem)
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

void		usage_setenv(int i, t_info *info, int j, char **tmp)
{
	if (j == 1)
	{
		write(2, "Invalid argument : \"put first arg\" \"put the value\"", 50);
		write(2, " \"put 1\" if you wanna overwrite it 0 if you don't\n", 50);
	}
	else if (j == 2)
	{
		write(2, "env: setenv ", 12);
		write(2, info->line_tab[i], ft_strlen(info->line_tab[i]));
		write(2, ": Invalid argument\n", 19);
		free_tab(tmp);
		free_tab(info->env_n);
	}
}

t_info		*set_env(t_info *info, char *elem, char *new_elem, int i)
{
	char	**str;
	int		line;

	line = 0;
	while (info->env[line])
	{
		str = ft_strsplit(info->env[line], '=');
		if (ft_strcmp(str[0], elem) == 0)
		{
			if (i != 0)
			{
				info->env[line] = new_line(info->env[line], elem, new_elem);
				free_tab(str);
				return (info);
			}
			free_tab(str);
			return (info);
		}
		free_tab(str);
		line++;
	}
	info->env[line] = new_line(info->env[line], elem, new_elem);
	info->env[line + 1] = NULL;
	return (info);
}

void		bi_setenv(t_info *info)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (info->line_tab[i])
	{
		if (ft_check_char(info->line_tab[1], '=') > 0)
		{
			usage_setenv(0, info, 1, NULL);
			return ;
		}
		if (info->line_tab[i + 2] && info->line_tab[i + 2][0] >= 48 &&
			info->line_tab[i + 2][0] <= 57 &&
			info->line_tab[i + 2][1] == '\0')
			j = ft_atoi(info->line_tab[i + 2]);
		else
		{
			usage_setenv(0, info, 1, NULL);
			return ;
		}
		info = set_env(info, info->line_tab[i], info->line_tab[i + 1], j);
		i = i + 3;
	}
}
