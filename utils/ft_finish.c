/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:26:12 by ceatgie           #+#    #+#             */
/*   Updated: 2022/05/25 14:33:23 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_finish(char *m)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(m);
	exit(EXIT_FAILURE);
}
