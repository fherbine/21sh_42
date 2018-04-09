/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:16:19 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 20:19:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		tst_debug(char *buff)
{
	ft_prints("%c %c %c", buff[0], buff[1], buff[2]);
}

int		tst(void)
{
	char	buffer[4];
	
	
	while(1)
	{
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		buffer[3] = 0;
		read(0, &buffer, 4);
		//tst_debug(buffer);
		if (buffer[0] == 4)
		{
			ft_prints("^D");
			return (0);
		}
		if (ft_strcmp(buffer, K_RIGHT) == 0)
			mv_right_cursor(1);
		if (ft_strcmp(buffer, K_LEFT) == 0)
			mv_left_cursor(1);
		if (ft_strlen(buffer) == 1)
			ft_prints("%s", buffer);
	}
	return (1);
}

int			main(void)
{
	t_trm	trm_params;
	
	trm_params = init_term();
	
	tst();
	//	Hey houston this is a tst -----------
	//	trm_params = display_prompt(trm_params);
	//	read(0, &buff, 4);
	//	if (ft_strcmp(buff, K_RIGHT) == 0)
	//	{
	//		ft_prints("tutu");
	//		mv_right_cursor(2);
	//	}
	//	sleep(2);
	// free(buff);
	//	trm_params = display_prompt(trm_params);
	// ---------------------------------------

	close_term();
	return(0);
}
