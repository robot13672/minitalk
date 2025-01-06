/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:41:59 by ikhristi          #+#    #+#             */
/*   Updated: 2023/02/24 18:11:17 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

int	g_msg;

void	ft_wrong_pid(void)
{
	ft_putstr_fd("Wrong PID of server", 2);
	exit(0);
}

void	ft_send_byte(char byte, int pid)
{
	int	i;
	int	kill_res;

	kill_res = 0;
	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill_res = kill(pid, SIGUSR2);
		else
			kill_res = kill(pid, SIGUSR1);
		if (kill_res == -1)
			ft_wrong_pid();
		if (usleep(300) == -1)
		{
			ft_putstr_fd("usleep error", 2);
			exit(1);
		}
		i--;
	}
}

void	ft_send_message(char *msg, int pid)
{
	while (*msg)
	{
		ft_send_byte(*msg, pid);
		msg++;
	}
	ft_send_byte(0, pid);
}

void	ft_receive_message(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message from server was received\n");
	g_msg = 1;
	exit(0);
}

int	main(int argc, char *argv[])
{
	int	pid;

	g_msg = 0;
	signal(SIGUSR1, ft_receive_message);
	if (argc != 3)
	{
		ft_putstr_fd("Wrong amount of arguments", 2);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (!argv[2][0])
		ft_putstr_fd("Message is empty", 2);
	ft_send_message(argv[2], pid);
	if (g_msg == 0)
		sleep(2147483647);
	return (0);
}
