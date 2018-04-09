/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:04:54 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 18:16:03 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_SH

# define SH21_SH

#include "../libft/libft.h"
#include "./ansi_mov.h"
#include "./ansi_keys.h"

typedef struct		s_trm
{
	struct winsize	sz; // infos about terminal size
}					t_trm;

// Functions in edit_actions.c
void				goto_cursor(int x, int y);

#endif
