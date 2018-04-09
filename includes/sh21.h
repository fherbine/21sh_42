/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:04:54 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 19:38:50 by fherbine         ###   ########.fr       */
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
	int				prompt_len;
}					t_trm;

// Functions in edit_actions.c
void				goto_cursor(int x, int y);
void				mv_right_cursor(int x);
void				mv_left_cursor(int x);
void				mv_up_cursor(int y);
void				mv_down_cursor(int y);

// Fuctions in shell_errors.c
void				termios_failure(void);

// Functions in change_term.c
t_trm				init_term(void);
void				close_term(void);

// Functions in prompt.c
t_trm				display_prompt(t_trm term_param);

#endif
