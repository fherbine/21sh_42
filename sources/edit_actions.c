/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:12:13 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 19:05:01 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

void	goto_cursor(int x, int y)
{
	ft_prints_fd(0, "%s[%d;%dH", K_ESC, x, y);
}

void	mv_right_cursor(int x)
{
	ft_prints_fd(0, "%s[%dC", K_ESC, x);
}

void	mv_left_cursor(int x)
{
	ft_prints_fd(0, "%s[%dD", K_ESC, x);
}

void	mv_up_cursor(int y)
{
	ft_prints_fd(0, "%s[%dA", K_ESC, y);
}

void	mv_down_cursor(int y)
{
	ft_prints_fd(0, "%s[%dB", K_ESC, y);
}
