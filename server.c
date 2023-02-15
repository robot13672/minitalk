/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:42:02 by ikhristi          #+#    #+#             */
/*   Updated: 2023/02/15 21:18:03 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

t_temp_state	g_temp_state;

void	init_temp_state(void)
{
	g_temp_state.client_pid = 0;
	g_temp_state.i = 0;
	g_temp_state.prog_char = 0;
}

void	ft_sighandler(int sig, siginfo_t *info, void *uncotext)
{
	int	bit;

	(void)uncontext;
	bit = sig - SIGUSR1;
	if (info->si_pid != g_temp_state.client_pid)
		init_temp_state();
	g_temp_state.prog_char = g_temp_state.prog_char << 1 | bit;
	g_temp_state.i++;
	if (g_temp_state.i == 8)
	{
		if (!g_temp_state.prog_char)
			kill(g_msg.client, SIGUSR1);
		ft_putstr_fd(g_temp_state.prog_char, 1);
		init_temp_state();
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server's PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(1);
}
