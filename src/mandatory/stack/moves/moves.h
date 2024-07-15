/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:58:55 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 05:59:57 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "../stack.h"

void	push(t_stack *stack, int mode);
void	reverse_rotate(t_stack *stack, int mode);
void	rotate(t_stack *stack, int mode);
void	swap(t_stack *stack, int mode);

#endif
