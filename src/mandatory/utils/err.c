/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:07:31 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 12:24:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file err.c
 * @dontinclude err.c
 * @line /\* *********
 * @until /\* *********
 */

#include <libft.h>

/**
 * @brief Print @p str to stderr and return @p retval
 * 
 * @param str 
 * @param retval 
 * @retval int 
 */
int	err(char *str, int retval)
{
	ft_putstr_fd(str, 2);
	return (retval);
}
