/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/17 08:30:35 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_minix.c
 * @dontinclude get_minix.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Get the index of the smallest element
 * 
 * @param[in] arr 
 * @param[in] len 
 * @retval int 
 */
int	get_minix(int *arr, int len)
{
	int	minix;

	len--;
	minix = len;
	while (len--)
	{
		if (arr[len] < arr[minix])
			minix = len;
	}
	return (minix);
}
