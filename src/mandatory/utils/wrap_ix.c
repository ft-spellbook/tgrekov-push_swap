/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_ix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:04:15 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/15 08:22:11 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Wrap a circular index, such that indices below zero are equal to
 * <tt>max - i</tt> and indices above @p max continue from zero
 * 
 * @param i 
 * @param max 
 * @retval int 
 */
int	wrap_ix(int i, int max)
{
	if (i < 0)
		return (max - 1);
	return (i % max);
}
