/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:46:44 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/27 19:38:50 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**init_env(char **envp, t_shvar **shvar)
{
	int		lvl;
	char	*tmp;
	char	*tmp2;

	lvl = 0;
	tmp = ftsh_search_envar(envp, "SHLVL");
	envp = ftsh_del_envar(shvar, "OLDPWD", envp);
	lvl = ft_atoi(tmp) + 1;
	free(tmp);
	tmp = ft_itoa(lvl);
	tmp2 = ft_strdup("SHLVL=");
	tmp2 = ft_strjoin(tmp2, tmp);
	free(tmp);
	envp = ftsh_del_envar(shvar, "SHLVL", envp);
	envp = ft_add_tab_elem(envp, tmp2);
	*shvar = add_shvar_elem(*shvar, tmp2);
	free(tmp2);
	return (envp);
}
