/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:49:27 by fherbine          #+#    #+#             */
/*   Updated: 2018/05/09 15:07:16 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tst.h"

void	init_term_struct(void)
{
	t_termios term;

	if (tcgetattr(0, term) == -1)
		exit(EXIT_FAILURE);

}

int		main(void)
{
	return (0);
}
