/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:22:38 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/16 10:24:22 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Get the index of the smallest element
 * 
 * @param arr 
 * @param len 
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
