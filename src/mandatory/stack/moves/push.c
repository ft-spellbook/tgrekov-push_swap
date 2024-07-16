/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:49:10 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 12:25:46 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push.c
 * @dontinclude push.c
 * @line /\* *********
 * @until /\* *********
 */

#include <ft_printf.h>
#include "../stack.h"

/**
 * @brief Push the first element out of @p src out and into @p dst
 * 
 * @param[in, out] src 
 * @param[in, out] dst 
 * @retval int 
 */
static int	_push(t_stack *src, t_stack *dst)
{
	int	i;

	if (!src->len)
		return (1);
	dst->len++;
	i = dst->len;
	while (i-- > 1)
		dst->n[i] = dst->n[i - 1];
	dst->n[0] = src->n[0];
	src->len--;
	i = 0;
	while (i++ < src->len)
		src->n[i - 1] = src->n[i];
	return (0);
}

/**
 * @brief Push the first element from stack 1 or 2 into the other stack,
 * depending if @p mode is set to 0 or 1
 * 
 * @param[in, out] stack 
 * @param[in] mode 
 */
void	push(t_stack *stack, int mode)
{
	if (!_push(&stack[mode], &stack[1 - mode]))
		ft_printf("p%c\n", 'b' - mode);
}
