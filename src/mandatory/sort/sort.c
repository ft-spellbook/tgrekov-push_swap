/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:49:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 10:00:03 by tgrekov          ###   ########.fr       */
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

static void	find_place(t_stack *stack, int mode, int n)
{
	int	i;
	int	dir;
	int	minix;

	minix = stack_minix(stack[mode]);
	i = minix;
	while (1)
	{
		i = wrap(i - 1, stack[mode].len);
		if (stack[mode].n[wrap(i - 1, stack[mode].len)] < n || i == minix)
			break ;
	}
	dir = 0;
	if (i < (stack[mode].len / 2))
		dir = 1;
	n = stack[mode].n[i];
	while (stack[mode].n[0] != n)
	{
		if (dir)
			rotate(stack, mode);
		else
			reverse_rotate(stack, mode);
	}
}

int	sort(t_stack *stack)
{
	push(stack, 0);
	while (stack[0].len)
	{
		//print_stack(stack[0]);
		//print_stack(stack[1]);
		find_place(stack, 1, stack[0].n[0]);
		push(stack, 0);
		//print_stack(stack[0]);
		//print_stack(stack[1]);
	}
	while (stack[1].len)
		push(stack, 1);
	//print_stack(stack[0]);
	return (0);
}
