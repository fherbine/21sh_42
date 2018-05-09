/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:49:27 by fherbine          #+#    #+#             */
/*   Updated: 2018/05/09 15:33:10 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tst.h"

/* ----------------------- utils ----------------------- */

void	init_term_struct(void)
{
	t_termios term;

	if (tcgetattr(0, &term) == -1)
		exit(EXIT_FAILURE);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		exit(EXIT_FAILURE);
}

void	close_term(void)
{
	t_termios term;

	if (tcgetattr(0, &term) == -1)
		exit(EXIT_FAILURE);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		exit(EXIT_FAILURE);
}

/* --------------------- tst func ------------------ */

void	tst(void)
{
	char	buffer[3];
	while (1)
	{
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		read(0, buffer, 3);
		printf("%c|%c|%c\n", buffer[0], buffer[1], buffer[2]);
		printf("%d|%d|%d\n", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return ;
		}
	}
}

/* --------------------- main ----------------------*/

int		main(void)
{
	init_term_struct();
	tst();
	close_term();
	return (0);
}
