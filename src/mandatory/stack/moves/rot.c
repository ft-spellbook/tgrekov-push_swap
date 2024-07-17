/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 06:08:41 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 08:16:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rot.c
 * @dontinclude rot.c
 * @line /\* *********
 * @until /\* *********
 */

#include <ft_printf.h>
#include "../stack.h"

/**
 * @brief Shift all elements in @p stack down
 * 
 * @param[in, out] stack 
 * @retval int 
 */
static int	_rot(t_stack stack)
{
	int	temp;
	int	i;

	if (stack.len < 2)
		return (1);
	temp = stack.n[0];
	i = 0;
	while (++i < stack.len)
		stack.n[i - 1] = stack.n[i];
	stack.n[i - 1] = temp;
	return (0);
}

/**
 * @brief Shift all elements in stack 1, 2, or both down,
 * depending on whether @p mode is set to 0, 1, or 2.
 * 
 * @param[in, out] stack 
 * @param[in] mode 
 */
void	rot(t_stack *stack, int mode)
{
	if (mode < 2 && !_rot(stack[mode]))
		ft_printf("r%c\n", 'a' + mode);
	if (mode == 2)
	{
		_rot(stack[0]);
		_rot(stack[1]);
		ft_printf("rr\n");
	}
}
