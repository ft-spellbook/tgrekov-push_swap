/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:05:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 12:25:10 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_sorted.c
 * @dontinclude is_sorted.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../utils/utils.h"
#include "stack.h"

/**
 * @brief Check if the contents of a stack are in the correct order relative
 * to the smallest element.
 * 
 * @param stack 
 * @param mode 
 * @retval int 
 */
int	is_sorted(t_stack *stack, int mode)
{
	int	minix;
	int	i;

	minix = get_minix(stack[mode].n, stack[mode].len);
	i = minix;
	while (1)
	{
		i = wrap_ix(i - (1 - 2 * mode), stack[mode].len);
		if (i == minix)
			break ;
		if (stack[mode].n[wrap_ix(i - (1 - 2 * mode), stack[mode].len)]
			> stack[mode].n[wrap_ix(i, stack[mode].len)])
			return (0);
	}
	return (1);
}
