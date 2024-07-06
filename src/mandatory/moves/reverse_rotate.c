/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 06:33:08 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/06 06:36:15 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

static int	_reverse_rotate(t_stack stack)
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

void	reverse_rotate(t_stack *stack, int mode)
{
	if (mode < 2 && !_reverse_rotate(stack[mode]))
		ft_printf("r%c\n", 'a' + mode);
	if (mode == 3 && (!_reverse_rotate(stack[0]) || !_reverse_rotate(stack[1])))
		ft_printf("rr\n");
}
