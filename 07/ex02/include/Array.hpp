/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:59 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 23:03:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY
# define ARRAY

# include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(const Array & other);
		~Array();
		Array &	operator=(const Array & other);

		Array(unsigned int n);

		T & operator[](size_t index);

		size_t	size() const;
	
		class	outBoundsException: public std::exception
		{
			public:
				const char *	what() const throw();
		};

	private:
		T *		arr;
		size_t	len;
};
#endif
