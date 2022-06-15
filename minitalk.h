/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:20:52 by mathis            #+#    #+#             */
/*   Updated: 2022/06/15 16:50:53 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

void	mt_putstr_fd(char *s, int fd);
void	mt_putnbr_fd(int n, int fd);
int		mt_atoi(const char *nptr);

#endif