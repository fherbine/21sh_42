/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:53:34 by fherbine          #+#    #+#             */
/*   Updated: 2018/05/09 16:29:25 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TST_H
# define TST_H

# include "ansi_keys.h"
# include "ansi_mov.h"
# include "../libft/libft.h"
# include <termios.h>

typedef	struct termios t_termios;

typedef struct		s_info
{
	struct s_info	*prev;
	char			*command;
	char			**line_tab;
	char			*line;
	char			**env;
	int				repl;
	char			**new_en;
	char			**env_n;
	int				do_ret;
	struct s_info	*next;
}					t_info;

typedef enum			e_separator
{
	;, &&, ||, |;
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


/* BUILTINS */





#endif
