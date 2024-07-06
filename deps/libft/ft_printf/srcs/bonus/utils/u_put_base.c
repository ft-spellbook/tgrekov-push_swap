/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_put_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:47 by tgrekov           #+#    #+#             */
/*   Updated: 2024/04/26 10:29:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/utils/u_put_base.c
 * @dontinclude srcs/bonus/utils/u_put_base.c
 * @line /\* *********
 * @until /\* *********
 */

#include <unistd.h>
#include "internal_types.h"
#include "../../../../libft.h"

static int	_u_put_base(t_ubiggest n,
	char *base, unsigned int base_len, int fd)
{
	int	res;

	res = 0;
	if (n > base_len - 1)
	{
		res = _u_put_base(n / base_len, base, base_len, fd);
		if (res == -1)
			return (-1);
	}
	if (write(fd, base + (n % base_len), 1) == -1)
		return (-1);
	return (res + 1);
}

/**
 * @brief Write unsigned number @p n on descriptor @p fd in base @p base.
 * 
 * @param[in] n 
 * @param[in] base 
 * @param[in] fd 
 * @retval int Number of characters written, or @p -1 on error.
 */
int	u_put_base(t_ubiggest n, char *base, int fd)
{
	return (_u_put_base(n, base, ft_strlen(base), fd));
}
