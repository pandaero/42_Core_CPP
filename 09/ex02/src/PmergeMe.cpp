/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 09:55:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

unsigned long	jacobsthalNumber(unsigned long idx)
{
	if (idx == 0)
		return (0);
	if (idx == 1)
		return (1);
	unsigned long	jacobsthal;
	jacobsthal = jacobsthalNumber(idx - 1) + 2 * jacobsthalNumber(idx - 2);
	return (jacobsthal);
}

vecSeq	jacobsthalSequenceUpToV(unsigned long limit)
{
	vecSeq			sequence;
	unsigned long	jacobsthalIndex = 3;
	while (jacobsthalNumber(jacobsthalIndex) < limit)
		sequence.push_back(jacobsthalNumber(jacobsthalIndex++));
	return (sequence);
}

listSeq	jacobsthalSequenceUpToL(unsigned long limit)
{
	listSeq			sequence;
	unsigned long	jacobsthalIndex = 3;
	while (jacobsthalNumber(jacobsthalIndex) < limit)
		sequence.push_back(jacobsthalNumber(jacobsthalIndex++));
	return (sequence);
}

struct s_vecPairGreaterThan
{
	bool operator()(vecPair a, vecPair b) const
	{
		vecPair::iterator	aEnd = a.end();--aEnd;
		vecPair::iterator	bEnd = b.end();--bEnd;
		return (*aEnd > *bEnd);
	}
}	vecPairGreaterThan;

struct s_listPairGreaterThan
{
	bool operator()(listPair a, listPair b) const
	{
		listPair::iterator	aEnd = a.end();--aEnd;
		listPair::iterator	bEnd = b.end();--bEnd;
		return (*aEnd > *bEnd);
	}
}	listPairGreaterThan;

void	mergeInsertSortL(list * container)
{
	if (container->size() == 1)
		return;

	pairList	pairs;
	straggler	strag(false, 0);

	// Determine and store straggler
	if (container->size() % 2 == 1)
	{
		strag.first = true;
		strag.second = *(--container->end());
		container->erase(--container->end());
	}
	// Create the pairs
	{
		list::iterator It = container->begin();
		while (It != container->end())
		{
			listPair	pair;
			pair.push_back(*It++);
			pair.push_back(*It++);
			pairs.push_back(pair);
		}
	}
	// Sort each pair
	{
		for (pairList::iterator It = pairs.begin(); It != pairs.end(); ++It)
		{
			listPair::iterator	Itp = It->begin();
			if (*Itp++ > *Itp)
				std::swap(*(It->begin()), *Itp);
		}
	}
	// Sort pair vector
	{
		pairs.sort(listPairGreaterThan);
	}
	// Create main chain
	listSeq	mainChain;
	{
		for (pairList::reverse_iterator It = pairs.rbegin(); It != pairs.rend(); ++It)
		{
			listPair::iterator	greaterElement = It->begin(); ++greaterElement;
			mainChain.push_back(*greaterElement);
		}
	}
	// Create pend chain
	listSeq	pendChain;
	{
		for (pairList::reverse_iterator It = pairs.rbegin(); It != pairs.rend(); ++It)
			pendChain.push_back(*(It->begin()));
	}
	// Insert pend elements to main chain
	{
		std::list<listSeq::reverse_iterator>	insertedIterators;
		listSeq::reverse_iterator	pendChainEnd = pendChain.rbegin();
		listSeq::iterator			insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *pendChainEnd);
		mainChain.insert(insertion, *pendChainEnd);
		insertedIterators.push_back(pendChainEnd++);

		listSeq	jacobsthalSeq = jacobsthalSequenceUpToL(pendChain.size());
		for (listSeq::reverse_iterator It = pendChainEnd; It != pendChain.rend(); ++It)
		{
			if (!jacobsthalSeq.empty())
			{
				listSeq::reverse_iterator	insertIt = pendChain.rend();
				std::advance(insertIt, -(*(jacobsthalSeq.begin()) - 1));
				listSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *insertIt);
				mainChain.insert(insertion, *insertIt);
				jacobsthalSeq.erase(jacobsthalSeq.begin());
				insertedIterators.push_back(insertIt);
			}
			else
			{
				listSeq::reverse_iterator	insertIt = pendChain.rbegin();
				while (find(insertedIterators.begin(), insertedIterators.end(), insertIt) != insertedIterators.end())
					++insertIt;
				listSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *insertIt);
				mainChain.insert(insertion, *insertIt);
				insertedIterators.push_back(insertIt);
			}
		}
	}
	// Insert straggler
	if (strag.first == true)
	{
		listSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), strag.second);
		mainChain.insert(insertion, strag.second);
	}
	*container = mainChain;
}

void	mergeInsertSortV(vec * container)
{
	if (container->size() == 1)
		return;
	pairVec		pairs;
	straggler	strag(false, 0);

	// Determine and store straggler
	if (container->size() % 2 == 1)
	{
		strag.first = true;
		strag.second = *(--container->end());
		container->erase(--container->end());
	}
	// Create the pairs
	{
		vec::iterator It = container->begin();
		while (It != container->end())
		{
			vecPair	pair;
			pair.push_back(*It++);
			pair.push_back(*It++);
			pairs.push_back(pair);
		}
	}
	// Sort each pair
	{
		for (pairVec::iterator It = pairs.begin(); It != pairs.end(); ++It)
			std::sort(It->begin(), It->end());
	}
	// Sort pair vector
	{
		std::sort(pairs.begin(), pairs.end(), vecPairGreaterThan);
	}
	// Create main chain
	vecSeq	mainChain;
	{
		for (pairVec::reverse_iterator It = pairs.rbegin(); It != pairs.rend(); ++It)
			mainChain.push_back((*It)[1]);
	}
	// Create pend chain
	vecSeq	pendChain;
	{
		for (pairVec::reverse_iterator It = pairs.rbegin(); It != pairs.rend(); ++It)
			pendChain.push_back((*It)[0]);
	}
	// Insert pend elements to main chain
	{
		std::vector<vecSeq::reverse_iterator>	insertedIterators;
		vecSeq::reverse_iterator	pendChainEnd = pendChain.rbegin();
		vecSeq::iterator			insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *pendChainEnd);
		mainChain.insert(insertion, *pendChainEnd);
		insertedIterators.push_back(pendChainEnd++);

		vecSeq	jacobsthalSeq = jacobsthalSequenceUpToV(pendChain.size());
		for (vecSeq::reverse_iterator It = pendChainEnd; It != pendChain.rend(); ++It)
		{
			if (!jacobsthalSeq.empty())
			{
				vecSeq::reverse_iterator	insertIt = pendChain.rend();
				std::advance(insertIt, -(*(jacobsthalSeq.begin()) - 1));
				vecSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *insertIt);
				mainChain.insert(insertion, *insertIt);
				jacobsthalSeq.erase(jacobsthalSeq.begin());
				insertedIterators.push_back(insertIt);
			}
			else
			{
				vecSeq::reverse_iterator	insertIt = pendChain.rbegin();
				while (find(insertedIterators.begin(), insertedIterators.end(), insertIt) != insertedIterators.end())
					++insertIt;
				vecSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *insertIt);
				mainChain.insert(insertion, *insertIt);
				insertedIterators.push_back(insertIt);
			}
		}
	}
	// Insert straggler
	if (strag.first == true)
	{
		vecSeq::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), strag.second);
		mainChain.insert(insertion, strag.second);
	}
	*container = mainChain;
}

template <class Iter>
void	mergeSort(Iter first, Iter last, size_t size)
{
	if (size > 1)
	{
		Iter mid = first;
		std::advance(mid, size / 2);
		mergeSort(first, mid, size / 2);
		mergeSort(mid, last, size - size / 2);
		std::inplace_merge(first, mid, last);
	}
}

template <class Iter>
bool	is_sorted(Iter first, Iter last)
{
	while (*first++ <= *first && first != last)
		(void) last;
	if (first != last)
		return (false);
	return (true);
}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other):
	_vector(other._vector),
	_list(other._list)
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe &	PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other)
	{
		new (this) PmergeMe(other);
	}
	return (*this);
}

unsigned long	PmergeMe::operator[](size_t i) const
{
	return (_vector[i]);
}

void	PmergeMe::push(unsigned long element)
{
	_vector.push_back(element);
	_list.push_back(element);
}

size_t	PmergeMe::size()
{
	return (_vector.size());
}

void	PmergeMe::mergeSortV()
{
	mergeSort(_vector.begin(), _vector.end(), _vector.size());
	if (!::is_sorted(_vector.begin(), _vector.end()))
		throw failedSortException();
}

void	PmergeMe::mergeInsertSortV()
{
	::mergeInsertSortV(&_vector);
	if (!::is_sorted(_vector.begin(), _vector.end()))
		throw failedSortException();
}

void	PmergeMe::mergeSortL()
{
	mergeSort(_list.begin(), _list.end(), _list.size());
	if (!::is_sorted(_list.begin(), _list.end()))
		throw failedSortException();
}

void	PmergeMe::mergeInsertSortL()
{
	::mergeInsertSortL(&_list);
	if (!::is_sorted(_list.begin(), _list.end()))
		throw failedSortException();
}

const char *	PmergeMe::failedSortException::what() const throw()
{
	return("Error: PmergeMe: unsuccessful sort of the container.");	
}
