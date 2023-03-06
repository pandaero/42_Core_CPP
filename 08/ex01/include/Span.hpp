/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:59 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 23:44:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN
# define SPAN

# include <numeric>
# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>
# include <cstdlib>
# include <ctime>
# include <cstdarg>

class	Span
{
	public:
		Span();
		Span(const Span &);
		~Span();
		Span &	operator=(const Span &);

		Span(unsigned int n);

		void			addNumber(int);
		void			addNumbers(int, ...);
		void			addVec(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
		void			addRandom(int);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	private:
		unsigned int		allocated;
		unsigned int		size;
		std::vector<int>	vector;

		class	overflowException: public std::exception
		{
			public:
				const char *	what() const throw();
		};
		class	noSpanException: public std::exception
		{
			public:
				const char *	what() const throw();
		};
};
#endif
