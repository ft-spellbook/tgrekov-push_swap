/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:49:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 08:11:48 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "utils/utils.h"
#include "stack/stack.h"

static int	find_place(t_stack *stack, int mode, int n)
{
	int	minix;
	int	i;
	int	next;

	minix = get_minix(stack[mode]);
	i = minix;
	if (mode)
		i = wrap_ix(minix + 1, stack[mode].len);
	while ((mode && stack[mode].n[i] > n)
		|| (!mode && stack[mode].n[i] < n))
	{
		i = wrap_ix(i + 1, stack[mode].len);
		if ((mode && i == wrap_ix(minix + 1, stack[mode].len))
			|| (!mode && i == minix))
			break ;
	}
	return (i);
}

static void	rotate_to(t_stack *stack, int mode, int i)
{
	int	dir;

	dir = 0;
	if (i < (stack[mode].len / 2))
		dir = 1;
	i = stack[mode].n[i];
	while (stack[mode].n[0] != i)
	{
		if (dir)
			rotate(stack, mode);
		else
			reverse_rotate(stack, mode);
	}
}

static int	rotate_cost(t_stack stack, int i)
{
	if (i < (stack.len / 2))
		return (i);
	return (stack.len - i);
}

static void	pick_and_push(t_stack *stack, int mode)
{
	int	costs[3];

	if (stack[1 - mode].len)
	{
		costs[0] = rotate_cost(stack[1 - mode],
				find_place(stack, 1 - mode, stack[mode].n[0]));
		costs[1] = rotate_cost(stack[1 - mode],
				find_place(stack, 1 - mode,
					stack[mode].n[wrap_ix(1, stack[mode].len)])) + 1;
		costs[2] = rotate_cost(stack[1 - mode],
				find_place(stack, 1 - mode,
					stack[mode].n[wrap_ix(-1, stack[mode].len)])) + 1;
		if (costs[0] > costs[1] || costs[0] > costs[2])
		{
			if (costs[1] < costs[2])
				rotate(stack, 0);
			else
				reverse_rotate(stack, 0);
		}
		rotate_to(stack, 1 - mode,
			find_place(stack, 1 - mode, stack[mode].n[0]));
	}
	push(stack, mode);
}

int	sort(t_stack *stack)
{
	int	costs[3];

	while (stack[0].len > 3 && !is_sorted(stack[0]))
		pick_and_push(stack, 0);
	if (!is_sorted(stack[0]))
	{
		rotate(stack, 0);
		swap(stack, 0);
	}
	while (stack[1].len)
		pick_and_push(stack, 1);
	rotate_to(stack, 0, get_minix(stack[0]));
	return (0);
}
