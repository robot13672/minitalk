/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:42:02 by ikhristi          #+#    #+#             */
/*   Updated: 2023/02/14 16:42:06 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

void	ft_sighandler(int sig, siginfo_t *info, void *uncotext)
{

}

int	main(void)
{
	struct sigaction	sa;

	printf("Server's PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

}