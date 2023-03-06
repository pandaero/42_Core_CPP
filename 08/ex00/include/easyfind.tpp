/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 13:30:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T & arr, int num)
{
	typename T::iterator	iter = std::find(arr.begin(), arr.end(), num);

	if (iter == arr.end())
		throw	outRangeException();
	return (iter);
}
