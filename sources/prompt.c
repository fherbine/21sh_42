/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:46:19 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 19:55:36 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

static char	*create_prompt(void)
{
	return (ft_strdup("$>"));
}

t_trm		display_prompt(t_trm term_param)
{
	char	*prompt;

	prompt = create_prompt();
	ft_prints_fd(0, "%s", prompt);
	term_param.prompt_len = ft_strlen(prompt);
	free(prompt);
	return (term_param);
}
