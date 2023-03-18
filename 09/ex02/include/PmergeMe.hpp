/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:54:14 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/18 21:03:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <algorithm>
# include <exception>

template <class Iter>
void	mergeSort(Iter, Iter, size_t);

template <class Iter>
void	mergeInsertSortV(Iter, Iter, size_t);

class	PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();
		PmergeMe &	operator=(const PmergeMe &);

		int	operator[](size_t) const;

		void	push(int);
		size_t	size();
		void	mergeSortV();
		void	mergeSortL();
};
#endif
