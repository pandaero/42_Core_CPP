/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:36 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 18:44:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER
# define WHATEVER

template <typename Type>
void	swap(Type & obj1, Type & obj2)
{
	Type	temp;

	temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}

template <typename Type>
Type &	min(Type & obj1, Type & obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

template <typename Type>
Type &	max(Type & obj1, Type & obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

#endif
