/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:54:14 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 02:56:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <exception>
# include <iterator>
# include <utility>
# include <vector>
# include <list>

template <class Iter>
void	mergeSort(Iter, Iter, size_t);

unsigned long	jacobsthalNumber(unsigned long);

typedef std::vector<unsigned long>	vec, vecSeq, vecPair;
typedef std::vector<vec>			pairVec;

typedef std::list<unsigned long>	list, listSeq, listPair;
typedef std::list<list>				pairList;

typedef std::pair<bool, unsigned long>	straggler;

struct s_vecPairGreaterThan;
struct s_listPairGreaterThan;

vecSeq	jacobsthalSequenceUpToV(unsigned long);
listSeq	jacobsthalSequenceUpToL(unsigned long);

void	mergeInsertSortV(vec *);
void	mergeInsertSortL(list *);

class	PmergeMe
{
	private:
		vec		_vector;
		list	_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();
		PmergeMe &	operator=(const PmergeMe &);

		unsigned long	operator[](size_t) const;

		void	push(unsigned long);
		size_t	size();
		void	mergeSortV();
		void	mergeInsertSortV();
		void	mergeSortL();
		void	mergeInsertSortL();
};
#endif
