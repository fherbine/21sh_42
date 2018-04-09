/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:20:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/04/09 18:22:33 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh21.h"

void	termios_failure(void)
{
	ft_prints_fd(2, "21sh: Cannot get/set the termios structure");
	exit(EXIT_FAILURE);
}
