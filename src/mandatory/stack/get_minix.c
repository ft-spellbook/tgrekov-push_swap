/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:03:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 08:20:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Get the index of the smallest element
 * 
 * @param stack 
 * @retval int 
 */
int	get_minix(t_stack stack)
{
	int	minix;

	stack.len--;
	minix = stack.len;
	while (stack.len--)
	{
		if (stack.n[stack.len] < stack.n[minix])
			minix = stack.len;
	}
	return (minix);
}
