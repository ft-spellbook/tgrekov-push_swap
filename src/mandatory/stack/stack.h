/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:03:43 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 08:11:39 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	len;
	int	*n;
}	t_stack;

void	push(t_stack *stack, int mode);
void	reverse_rotate(t_stack *stack, int mode);
void	rotate(t_stack *stack, int mode);
void	swap(t_stack *stack, int mode);

int		get_minix(t_stack stack);
int		is_sorted(t_stack stack);

#endif
