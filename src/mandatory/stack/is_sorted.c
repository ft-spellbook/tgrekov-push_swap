/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:05:56 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 08:09:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "stack.h"

int	is_sorted(t_stack stack)
{
	int	minix;
	int	i;

	minix = get_minix(stack);
	i = minix;
	while (1)
	{
		i = wrap_ix(i - 1, stack.len);
		if (i == minix)
			break ;
		if (stack.n[wrap_ix(i - 1, stack.len)] > stack.n[wrap_ix(i, stack.len)])
			return (0);
	}
	return (1);
}
