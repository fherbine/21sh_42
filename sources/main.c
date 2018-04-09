/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:16:19 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 19:27:31 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			main(void)
{
	t_trm	trm_params;
	
	trm_params = init_term();
	// main code
	
	//	Hey houston this is a tst
	display_prompt();
	// -----------------------------
	close_term();
	return(0);
}
