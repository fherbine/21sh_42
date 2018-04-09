/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:20:42 by llacaze           #+#    #+#             */
/*   Updated: 2018/03/05 13:09:51 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			bi_echo_sec(t_info *info, int i, int j)
{
	char	*tmp;

	if (j == 0)
	{
		tmp = get_env(info->env, "HOME");
		if (ft_strcmp(tmp, "NULL") != 0)
			ft_putstr(tmp);
		i++;
		free(tmp);
		info->line_tab[i] ? write(1, " ", 1) : 0;
		return (i);
	}
	else if (j == 1)
	{
		tmp = get_env(info->env, info->line_tab[i] + 1);
		if (info->line_tab[i][1] == '\0')
			ft_putchar(info->line_tab[i][0]);
		if (ft_strcmp(tmp, "NULL") != 0)
			ft_putstr(tmp);
		i++;
		free(tmp);
		info->line_tab[i] ? write(1, " ", 1) : 0;
		return (i);
	}
	return (i);
}

t_info		*bi_echo_fourth(t_info *info, int i)
{
	int		j;

	j = 0;
	info->do_ret = 0;
	if (ft_strcmp(info->line_tab[i], "~") == 0)
	{
		i = bi_echo_sec(info, i, 0);
		info->do_ret = 1;
	}
	else if (info->line_tab[i][0] == '$')
	{
		info->do_ret = 1;
		i = bi_echo_sec(info, i, 1);
	}
	else
	{
		i = bi_echo_third(info, i, 1);
		info->line_tab[i] != '\0' ? write(1, " ", 1) : 0;
	}
	return (info);
}

int			bi_echo_third(t_info *info, int i, int k)
{
	int		j;

	j = 0;
	if (k == 1)
	{
		while (info->line_tab[i][j])
		{
			if (info->line_tab[i][j] == '\\' &&
			ft_isascii(info->line_tab[i][j + 1]))
				ft_putchar(info->line_tab[i][j]);
			else
				ft_putchar(info->line_tab[i][j]);
			j++;
		}
		i++;
	}
	else
	{
		info = bi_echo_fourth(info, i);
	}
	return (i);
}

void		bi_echo(t_info *info)
{
	int		i;
	int		k;

	i = 1;
	if (info->line_tab[i] == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	while (ft_strcmp(info->line_tab[i], "-n") == 0)
		i++;
	k = i;
	while (info->line_tab[i])
	{
		i = bi_echo_third(info, i, 0);
		i++;
	}
	if (k != 1)
	{
		write(1, "\033[0;4;47m", 9);
		ft_putchar('%');
		ft_putstr("\033[0m");
	}
	write(1, "\n", 1);
}
