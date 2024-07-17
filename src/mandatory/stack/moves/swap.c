/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:36:42 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/17 08:35:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
 * @dontinclude swap.c
 * @line /\* *********
 * @until /\* *********
 */

#include <ft_printf.h>
#include "../stack.h"

/**
 * @brief Swap the first two elements in @p stack
 * 
 * @param[in, out] stack 
 * @retval int 
 */
static int	_swap(t_stack stack)
{
	int	temp;

	if (stack.len < 2)
		return (1);
	temp = stack.n[0];
	stack.n[0] = stack.n[1];
	stack.n[1] = temp;
	return (0);
}

/**
 * @brief Swap the first two elements in stacks 1, 2, or both,
 * depending on whether @p mode is set to 0, 1, or 2.
 * 
 * @param[in, out] stack 
 * @param[in] mode 
 */
void	swap(t_stack *stack, int mode)
{
	if (mode < 2 && !_swap(stack[mode]))
		ft_printf("s%c\n", 'a' + mode);
	if (mode == 2)
	{
		_swap(stack[0]);
		_swap(stack[1]);
		ft_printf("ss\n");
	}
}
