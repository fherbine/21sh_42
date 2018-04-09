/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:04:54 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 18:40:27 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_SH

# define SH21_SH

# include "../libft/libft.h"
# include "./ansi_mov.h"
# include "./ansi_keys.h"

# include <termios.h>
# include <sys/ioctl.h>

typedef struct		s_trm
{
	struct winsize	sz; // infos about terminal size
}					t_trm;

// Functions in edit_actions.c
void				goto_cursor(int x, int y);

// Fuctions in shell_errors.c
void				termios_failure(void);

// Functions in change_term.c
t_trm				init_term(void);
void				close_term(void);

#endif
