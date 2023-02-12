/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:42:02 by ikhristi          #+#    #+#             */
/*   Updated: 2023/02/12 20:33:13 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

int	main(void)
{
	struct sigaction	s_sigaction;

	printf("Server's PID is: %d\n", getpid());

}