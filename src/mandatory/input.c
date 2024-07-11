/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:18:07 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 09:10:32 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file input.c
 * @dontinclude input.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <ft_printf.h>
#include "utils/utils.h"
#include "stack.h"

/**
 * @brief Split input if it was provided as a single argument, validate input
 * length, and allocate stacks
 * 
 * @param[in] argc 
 * @param[in] argv 
 * @param[out] arg2 
 * @param[out] stack 
 * @retval int 
 */
static int	init_stacks(int argc, char **argv, char ***arg2, t_stack *stack)
{
	*arg2 = 0;
	if (argc == 1)
	{
		*arg2 = ft_split(argv[0], ' ');
		if (!arg2)
			return (err("malloc():", 1));
		argc = arr_len((void **) *arg2);
	}
	if (argc < 2)
	{
		ft_printf("%>Too few arguments\n", 2);
		return (1);
	}
	stack[1].n = 0;
	stack[1].len = 0;
	stack[0].n = malloc(sizeof(int) * argc);
	if (!stack[0].n)
		return (err("malloc():", 1));
	stack[1].n = malloc(sizeof(int) * argc);
	if (!stack[1].n)
		return (err("malloc():", 1));
	return (0);
}

/**
 * @brief Check that @p parsed is identical to the source @p arg
 * when converted back into a string
 * 
 * @param[in] arg 
 * @param[in] parsed 
 * @retval int 
 */
static int	validate_arg(char *arg, int parsed)
{
	char	*converted;
	size_t	len;
	int		res;

	converted = ft_itoa(parsed);
	if (!converted)
	{
		perror("malloc():");
		return (1);
	}
	len = ft_strlen(converted);
	if (ft_strlen(arg) != len)
	{
		ft_printf("%>Argument \"%s\" not a number\n", 2, arg);
		return (1);
	}
	res = ft_strncmp(arg, converted, len);
	free(converted);
	if (res)
		ft_printf("%>Argument \"%s\" not a number\n", 2, arg);
	return (res);
}

/**
 * @brief Check if @p n is already present in the @p stack
 * 
 * @param[in] stack 
 * @param[in] n 
 * @retval int 
 */
static int	duplicate_check(t_stack stack, int n)
{
	stack.len--;
	while (stack.len--)
	{
		if (stack.n[stack.len] == n)
		{
			ft_printf("%>Argument \"%d\" duplicated\n", 2, n);
			return (1);
		}
	}
	return (0);
}

/**
 * @brief Parse and validate input arguments and add them to the first stack
 * 
 * @param[in] argv 
 * @param[out] stack 
 * @retval int 
 */
static int	parse_args(char **argv, t_stack *stack)
{
	stack[0].len = 0;
	while (*argv)
	{
		stack[0].n[stack[0].len++] = ft_atoi(*argv);
		if (validate_arg(*argv, stack[0].n[stack[0].len - 1]))
			return (1);
		if (duplicate_check(stack[0], stack[0].n[stack[0].len - 1]))
			return (1);
		argv++;
	}
	return (0);
}

/**
 * @brief Parse and validate program input,
 * initialize stacks and fill the first stack
 * 
 * @param[in] argc 
 * @param[in] argv 
 * @param[out] stack 
 * @retval int 
 */
int	input(int argc, char **argv, t_stack *stack)
{
	char	**arg2;
	int		status;

	if (init_stacks(--argc, ++argv, &arg2, stack))
	{
		if (arg2)
			arr_free((void **) arg2);
		return (1);
	}
	if (arg2)
	{
		status = parse_args(arg2, stack);
		arr_free((void **) arg2);
	}
	else
		status = parse_args(argv + 1, stack);
	return (status);
}
