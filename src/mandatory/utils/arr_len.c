/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:40:00 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/17 08:31:18 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file arr_len.c
 * @dontinclude arr_len.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Count number of elements in a null-terminated array.
 * 
 * @param[in] arr Array to count
 * @retval int Length of @p arr
 */
int	arr_len(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
