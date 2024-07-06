/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:10:14 by tgrekov           #+#    #+#             */
/*   Updated: 2023/11/04 22:47:32 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @dontinclude ft_putnbr_fd.c
 * @line /\* *********
 * @until /\* *********
 */

#include "libft.h"

/**
 * @brief Converts integer @p n to it's ASCII representation
 * and writes it to file descriptor @p fd
 * 
 * @param[in] n Integer to convert
 * @param[in] fd File descriptor to write to
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
