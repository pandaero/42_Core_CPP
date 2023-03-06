/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:59 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 13:36:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
# define EASYFIND

# include <algorithm>
# include <exception>

class	outRangeException: public std::exception
{
	public:
		const char *	what() const throw();	
};

template <typename T>
typename T::iterator	easyfind(T & arr, int num);

#endif
