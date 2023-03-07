/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:27:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/07 12:42:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename Type>
MutantStack<Type>::MutantStack()
{

}

template <typename Type>
MutantStack<Type>::MutantStack(const MutantStack<Type> & other)
{
	this->c = other.c;
}

template <typename Type>
MutantStack<Type>::~MutantStack()
{

}

template <typename Type>
MutantStack<Type> &	MutantStack<Type>::operator=(const MutantStack<Type> & other)
{
	if (this != &other)
		this->c = other.c;
	return (*this);
}

template <typename Type>
typename MutantStack<Type>::iterator		MutantStack<Type>::begin()
{
	return (this->c.begin());
}

template <typename Type>
typename MutantStack<Type>::iterator		MutantStack<Type>::end()
{
	return (this->c.end());
}

template <typename Type>
typename MutantStack<Type>::const_iterator	MutantStack<Type>::begin() const
{
	return (this->c.begin());
}

template <typename Type>
typename MutantStack<Type>::const_iterator	MutantStack<Type>::end() const
{
	return (this->c.end());
}

template <typename Type>
typename MutantStack<Type>::reverse_iterator		MutantStack<Type>::rbegin()
{
	return (this->c.rbegin());
}

template <typename Type>
typename MutantStack<Type>::reverse_iterator		MutantStack<Type>::rend()
{
	return (this->c.rend());
}

template <typename Type>
typename MutantStack<Type>::const_reverse_iterator	MutantStack<Type>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename Type>
typename MutantStack<Type>::const_reverse_iterator	MutantStack<Type>::rend() const
{
	return (this->c.rend());
}
