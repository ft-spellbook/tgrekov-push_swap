/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:03:43 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 12:25:05 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file stack.h
 * @dontinclude stack.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	len;
	int	*n;
}	t_stack;

void	push(t_stack *stack, int mode);
void	r_rot(t_stack *stack, int mode);
void	rot(t_stack *stack, int mode);
void	swap(t_stack *stack, int mode);

int		is_sorted(t_stack *stack, int mode);

#endif
