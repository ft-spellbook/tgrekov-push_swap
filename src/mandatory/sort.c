/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:49:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 12:26:21 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort.c
 * @dontinclude sort.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "utils/utils.h"
#include "stack/stack.h"

/**
 * @brief Find appropriate index for @p n in <tt>stack[mode]</tt>
 * 
 * @param stack 
 * @param mode 
 * @param n 
 * @retval int 
 */
static int	pick_i(t_stack *stack, int mode, int n)
{
	int	minix;
	int	i;
	int	next;

	minix = get_minix(stack[mode].n, stack[mode].len);
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

/**
 * @brief Rotate to an index with rotate or reverse rotate, depending
 * on which is shorter
 * 
 * @param stack 
 * @param mode 
 * @param i 
 */
static void	rot_i(t_stack *stack, int mode, int i)
{
	int	dir;

	dir = 0;
	if (i < (stack[mode].len / 2 + 1))
		dir = 1;
	i = stack[mode].n[i];
	while (stack[mode].n[0] != i)
	{
		if (dir)
			rot(stack, mode);
		else
			r_rot(stack, mode);
	}
}

/**
 * @brief Determine move cost of rotating to an index, considering whether it
 * is shorter to rotate or reverse rotate
 * 
 * @param stack 
 * @param i 
 * @retval int 
 */
static int	rot_cost(t_stack stack, int o_i, int o_len, int i)
{
	if (i < (stack.len / 2 + 1))
	{
		if (o_i < (o_len / 2 + 1))
		{
			if (i >= o_i)
				return (i);
			return (o_i);
		}
		return (i + (o_len - o_i));
	}
	if (o_i < (o_len / 2 + 1))
		return (stack.len - i + o_i);
	if ((stack.len - i) >= (o_len - o_i))
		return (stack.len - i);
	return (o_len - o_i);
}

/**
 * @brief Determine which element to push from stack @p mode
 * to the opposite stack by comparing their movement costs
 * 
 * @param stack 
 * @param mode 
 */
static void	pick(t_stack *stack, int mode, int *costs)
{
	int	i;
	int	minix;

	if (!stack[1 - mode].len)
		return ;
	i = -1;
	while (++i < stack[mode].len)
		costs[i] = rot_cost(stack[1 - mode], i, stack[mode].len,
				pick_i(stack, 1 - mode, stack[mode].n[i]));
	minix = get_minix(costs, i);
	i = minix;
	if (minix > (stack[mode].len / 2))
		i = minix - stack[mode].len;
	while (i)
	{
		if (i > 0)
			rot(stack, fallback((pick_i(stack, 1 - mode, stack[mode].n[minix])
						< (stack[mode].len / 2 + 1)) * 2, mode));
		else
			r_rot(stack, fallback((pick_i(stack, 1 - mode, stack[mode].n[minix])
						> (stack[mode].len / 2)) * 2, mode));
		i += 1 + (i > 0) * -2;
	}
	rot_i(stack, 1 - mode, pick_i(stack, 1 - mode, stack[mode].n[0]));
}

/**
 * @brief Output all instructions required to sort stack a
 * 
 * @param stack 
 * @retval int 
 */
int	sort(t_stack *stack)
{
	int	*costs;

	costs = malloc(sizeof(int) * stack[0].len);
	if (!costs)
		return (err("Error\n", 1));
	while (stack[0].len > 3 && !is_sorted(stack, 0))
	{
		pick(stack, 0, costs);
		push(stack, 0);
	}
	if (!is_sorted(stack, 0))
	{
		swap(stack, 0);
		rot_i(stack, 0, get_minix(stack[0].n, stack[0].len));
	}
	while (stack[1].len)
	{
		pick(stack, 1, costs);
		push(stack, 1);
	}
	rot_i(stack, 0, get_minix(stack[0].n, stack[0].len));
	free(costs);
	return (0);
}
