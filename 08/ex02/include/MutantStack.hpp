/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:59 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/07 12:40:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

# include <stack>
# include <iostream>
# include <algorithm>

template <typename Type>
class	MutantStack: public std::stack<Type>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<Type> &);
		~MutantStack();
		MutantStack &	operator=(const MutantStack<Type> &);

		typedef typename std::stack<Type>::container_type::iterator iterator;
		typedef typename std::stack<Type>::container_type::const_iterator const_iterator;
		typedef typename std::stack<Type>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<Type>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};
#endif
