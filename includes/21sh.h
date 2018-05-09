/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:53:34 by fherbine          #+#    #+#             */
/*   Updated: 2018/05/09 15:44:11 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TST_H
# define TST_H

# include "ansi_keys.h"
# include "ansi_mov.h"
# include "../libft/libft.h"
# include <termios.h>

typedef	struct termios t_termios;

typedef enum			e_separator
{
	\;, &&, ||, |;
}						t_separator;

typedef enum			e_redir
{
	<, >, <<, >>;
}						t_redir;

typedef struct			s_parsed
{
	t_separator			sep;
	t_redir				red;
	char				*cmd;
	int					argc;
	char				**argvs;
	struct s_parsed		*next;
}						t_parsed;

#endif
