/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:43:05 by llacaze           #+#    #+#             */
/*   Updated: 2018/04/09 17:48:05 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

/*
** A apapeler :
** sig_handler avec la fonction signal(SIGINT, sig_handler) dans le cas ou child pid est different de -1 apres avoir fork
** et avant le wait de l'adress du pid du child;
** sig_hand_emp pareil que l'autre mais cette fois a placer juste avant de read et de balancer 
** les fonctions de check et d execution
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