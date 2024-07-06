/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:07:48 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/06 04:21:51 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	input(int argc, char **argv, t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	stack[2];

	if (input(argc, argv, stack))
	{
		free(stack[0].n);
		free(stack[1].n);
		return (1);
	}
	free(stack[0].n);
	free(stack[1].n);
	return (0);
}
