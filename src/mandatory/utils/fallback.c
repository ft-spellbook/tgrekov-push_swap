/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fallback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:32:03 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/17 08:31:12 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fallback.c
 * @dontinclude fallback.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Return a if non-zero, otherwise return b
 * 
 * @param[in] a 
 * @param[in] b 
 * @retval int 
 */
int	fallback(int a, int b)
{
	if (a)
		return (a);
	return (b);
}
