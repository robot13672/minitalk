/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:04 by ikhristi          #+#    #+#             */
/*   Updated: 2023/02/12 20:28:37 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>
# include <sys/signal.h>

typedef struct s_temp_state{
	int		i;
	char	prog_char;
	int		client_pid;
}t_temp_state;

#endif