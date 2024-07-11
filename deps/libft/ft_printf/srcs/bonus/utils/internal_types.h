/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:40:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/11 08:16:09 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file srcs/bonus/utils/internal_types.h
 * @dontinclude srcs/bonus/utils/internal_types.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef INTERNAL_TYPES_H
# define INTERNAL_TYPES_H

# include <stdint.h>
# include <unistd.h>

/**
 * @brief Convenience typedef for largest signed type I need to handle.
 */
typedef long long			t_biggest;
/**
 * @brief Convenience typedef for largest unsigned type I need to handle.
 * 
 */
typedef unsigned long long	t_ubiggest;
/**
 * @brief Largest value that fits in @ref t_biggest
 */
# define T_BIGGEST_MAX 9223372036854775807LL

/**
 * @brief If @p _WCHAR_H_ is defined, set to @p wint_t. Set to @p int otherwise.
 */
# ifdef _WCHAR_H_

typedef wint_t				t_wint_t;
# else

typedef int					t_wint_t;
# endif

/**
 * @brief If @p _PTRDIFF_T is defined, set to @p ptrdiff_t.
 * Set to @p long otherwise.
 */
# ifdef _PTRDIFF_T

typedef ptrdiff_t			t_ptrdiff_t;
# else

typedef long				t_ptrdiff_t;
# endif

# ifdef intmax_t

typedef intmax_t			t_intmax_t;
# else

typedef long int			t_intmax_t;
# endif

#endif
