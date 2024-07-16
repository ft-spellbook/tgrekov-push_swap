/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 06:33:08 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 08:15:31 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file r_rot.c
 * @dontinclude r_rot.c
 * @line /\* *********
 * @until /\* *********
 */

#include <ft_printf.h>
#include "../stack.h"

static int	_r_rot(t_stack stack)
{
	int	temp;
	int	i;

	if (stack.len < 2)
		return (1);
	temp = stack.n[stack.len - 1];
	i = stack.len;
	while (i-- > 1)
		stack.n[i] = stack.n[i - 1];
	stack.n[0] = temp;
	return (0);
}

void	r_rot(t_stack *stack, int mode)
{
	if (mode < 2 && !_r_rot(stack[mode]))
		ft_printf("rr%c\n", 'a' + mode);
	if (mode == 2)
	{
		_r_rot(stack[0]);
		_r_rot(stack[1]);
		ft_printf("rrr\n");
	}
}
