/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:44:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 22:02:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER
# define ITER

template <typename Type>
void	iter(Type * arr, int len, void (*f)(Type & element))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif
