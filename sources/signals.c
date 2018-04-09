/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:43:05 by llacaze           #+#    #+#             */
/*   Updated: 2018/04/09 19:00:35 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

/*
** A apapeler :
** sig_handler with the signal function signal(SIGINT, sig_handler) when child pid is different of -1 after the fork
** and before the wait of the adress of the pid;
** sig_hand_emp as same as the other function but this time you put it just before the read
*/

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