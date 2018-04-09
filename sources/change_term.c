/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:17:41 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 18:36:38 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

t_trm				init_term(void)
{
	struct termios	term;
	t_trm			trm_params;

	if (tcgetattr(0, &term) == -1)
		termios_failure();
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		termios_failure();
	ioctl(1, TIOCGWINSZ, &(trm_params.sz));
	return (trm_params);
}

void				close_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		termios_failure();
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		termios_failure();
}
