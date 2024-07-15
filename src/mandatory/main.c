/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:07:48 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 09:10:36 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack/stack.h"

int	input(int argc, char **argv, t_stack *stack);
int	sort(t_stack *stack);

int	main(int argc, char **argv)
{
	int		status;
	t_stack	stack[2];

	if (argc == 1)
		return (0);
	stack[0].n = 0;
	stack[1].n = 0;
	status = input(argc, argv, stack);
	if (!status)
		status = sort(stack);
	free(stack[0].n);
	free(stack[1].n);
	return (status);
}
