/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:38:09 by llacaze           #+#    #+#             */
/*   Updated: 2018/03/08 13:54:42 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\r\n", 2);
	}
}

void	sig_hand_emp(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n>$", 3);
	}
}

void	error_oldpwd(char *tmp)
{
	write(2, "$OLDPWD doesn't exist, add it with setenv.\n", 43);
	free(tmp);
}
