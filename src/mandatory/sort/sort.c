/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:49:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 03:34:56 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "../stack.h"
#include "../moves/moves.h"

static void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.len)
		ft_printf("%d ", stack.n[i++]);
	ft_printf("\n");
}

static int	stack_minix(t_stack stack)
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

static int	wrap(int i, int max)
{
	if (i < 0)
		return (max - 1);
	return (i % max);
}

static int	find_place(t_stack stack, int n, int mode)
{
	int	minix;
	int	i;

	minix = stack_minix(stack);
	//ft_printf("m%d\n", minix);
	if (!mode)
	{
		i = wrap(minix - 1, stack.len);
		while (stack.n[i] > n && i != minix)
			i = wrap(i - 1, stack.len);
	}
	else
	{
		i = minix;
		while (stack.n[i] < n)
		{
			i = wrap(i + 1, stack.len);
			if (i == minix)
				break ;
		}
	}
	//ft_printf("i%d\n", i);
	return (i);
}

static void	rotate_to(t_stack *stack, int mode, int i, int both)
{
	int	dir;

	dir = 0;
	if (i < (stack[mode].len / 2))
		dir = 1;
	i = stack[mode].n[i];
	while (stack[mode].n[0] != i)
	{
		if (dir && both == 1)
		{
			rotate(stack, 2);
			both = 0;
		}
		else if (dir)
			rotate(stack, mode);
		if (!dir && both == -1)
		{
			reverse_rotate(stack, 2);
			both = 0;
		}
		else if (!dir)
			reverse_rotate(stack, mode);
	}
	if (both == 1)
		rotate(stack, 1 - mode);
	if (both == -1)
		reverse_rotate(stack, 1 - mode);
}

static int	rotate_cost(t_stack stack, int i)
{
	if (i < (stack.len / 2))
		return (i);
	return (stack.len - i);
}

static int	is_sorted(t_stack stack)
{
	int	minix;
	int	i;

	minix = stack_minix(stack);
	i = minix;
	while (1)
	{
		i = wrap(i - 1, stack.len);
		if (i == minix)
			break ;
		if (stack.n[wrap(i - 1, stack.len)] > stack.n[wrap(i, stack.len)])
			return (0);
	}
	return (1);
}

static void	pick_and_push(t_stack *stack, int mode)
{
	int	costs[3];

	if (stack[1 - mode].len)
	{
		costs[0] = rotate_cost(stack[1 - mode], find_place(stack[1 - mode], stack[mode].n[0], mode));
		//costs[1] = rotate_cost(stack[1 - mode], find_place(stack[1 - mode], stack[mode].n[wrap(1, stack[mode].len)])) + 1;
		//costs[2] = rotate_cost(stack[1 - mode], find_place(stack[1 - mode], stack[mode].n[wrap(-1, stack[mode].len)])) + 1;
		//if ((costs[0] < costs[1] && costs[0] < costs[2]) || (costs[0] == costs[1] && costs[1] == costs[2]))
		//print_stack(stack[0]);
			rotate_to(stack, 1 - mode, find_place(stack[1 - mode], stack[mode].n[0], mode), 0);
		//print_stack(stack[0]);
		//else if (costs[1] < costs[2])
		//	rotate_to(stack, 1 - mode, find_place(stack[1 - mode], stack[mode].n[wrap(1, stack[mode].len)]), 1);
		//else
		//	rotate_to(stack, 1 - mode, find_place(stack[1 - mode], stack[mode].n[wrap(-1, stack[mode].len)]), -1);
	}
	push(stack, mode);
}

int	sort(t_stack *stack)
{
	int	costs[3];

	while (stack[0].len > 3) // && !is_sorted(stack[0])
		pick_and_push(stack, 0);
	if (!is_sorted(stack[0]))
	{
		rotate(stack, 0);
		swap(stack, 0);
	}
	//Placing on incorrect side
	while (stack[1].len)
		pick_and_push(stack, 1);
	rotate_to(stack, 0, stack_minix(stack[0]), 0);
	//print_stack(stack[0]);
	return (0);
}
