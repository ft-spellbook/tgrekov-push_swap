/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:36 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 06:49:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file err.c
 * @dontinclude err.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdio.h>

/**
 * @brief Wrapper around <tt>perror()</tt> that always returns @p retval.
 * 
 * @param str String to pass to <tt>perror()</tt>
 * @param retval Return value
 * @retval int @p retval
 */
int	err(const char *str, int retval)
{
	perror(str);
	return (retval);
}
