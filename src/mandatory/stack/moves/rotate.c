/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 06:08:41 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 06:22:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "../stack.h"

static int	_rotate(t_stack stack)
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

void	rotate(t_stack *stack, int mode)
{
	if (mode < 2 && !_rotate(stack[mode]))
		ft_printf("r%c\n", 'a' + mode);
	if (mode == 3 && (!_rotate(stack[0]) || !_rotate(stack[1])))
		ft_printf("rr\n");
}
