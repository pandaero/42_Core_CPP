/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI-List.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:22:13 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 02:34:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <iostream>
#include <utility>
#include <vector>
#include <list>

typedef	std::list<unsigned long>				sequence, chain, vectorPair;
typedef std::list<std::list<unsigned long> >	pairVector;

unsigned long	jacobsthalNumber(unsigned long num)
{
	if (num == 0)
		return (0);
	if (num == 1)
		return (1);
	unsigned long	jacobsthal;
	jacobsthal = jacobsthalNumber(num - 1) + 2 * jacobsthalNumber(num - 2);
	return (jacobsthal);
}

std::list<unsigned long>	jacobsthalSequenceUpTo(size_t limit)
{
	std::list<unsigned long>	sequence;
	unsigned int	jacobsthalIndex = 3;
	while (jacobsthalNumber(jacobsthalIndex) < limit)
		sequence.push_back(jacobsthalNumber(jacobsthalIndex++));
	return (sequence);
}

struct s_pairGreaterThan
{
	bool operator()(std::list<unsigned long> a, std::list<unsigned long> b) const
	{
		std::list<unsigned long>::iterator	aEnd = a.end();--aEnd;
		std::list<unsigned long>::iterator	bEnd = b.end();--bEnd;
		return *aEnd > *bEnd;
	}
}	pairGreaterThan;

int	main()
{
	chain	in;

	in.push_back(5);
	in.push_back(4);
	in.push_back(6);
	in.push_back(7);
	in.push_back(3);
	in.push_back(1);
	in.push_back(2);
	in.push_back(81);
	in.push_back(123);
	in.push_back(11);
	in.push_back(14);

	// Display input list
	{
		std::cout << "===== ===== INPUT ===== =====" << std::endl;
		int	i = 0;
		for (chain::iterator it = in.begin(); it != in.end(); ++it)
		{
			std::cout << *it << " ";
			if (i % 2 == 1)
				std::cout << "| ";
			++i;
		}
		std::cout << std::endl;
	}
	// Algorithm sorting elements
	pairVector						pairs;
	std::pair<bool, unsigned long> 	straggler(false, 0);
	// Determine whether there is a straggler and remove from input
	if (in.size() % 2 == 1)
	{
		straggler.first = true;
		straggler.second = *(--in.end());
		in.erase(--in.end());
	}
	// Create the pairs
	{
		chain::iterator ItBegin = in.begin();
		chain::iterator	ItEnd = in.end();
		while (ItBegin != ItEnd)
		{
			vectorPair	pair;
			pair.push_back(*ItBegin++);
			pair.push_back(*ItBegin++);
			pairs.push_back(pair);
		}
	}
	// Display pair list
	{
		std::cout << "===== ===== PAIRS ===== =====" << std::endl;
		for (pairVector::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			chain::iterator	pIt = it->begin();
			std::cout << *pIt++ << ", " << *pIt << std::endl;
		}
	}
	// Sort each pair's elements
	for (pairVector::iterator It = pairs.begin(); It != pairs.end(); ++It)
	{
		vectorPair::iterator	ItpBeg = It->begin();
		if (*ItpBeg++ > *ItpBeg)
			std::swap(*(It->begin()), *ItpBeg);
	}
	// Display pair list
	{
		std::cout << "===== ===== PAIRS ===== =====" << std::endl;
		for (pairVector::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			chain::iterator	pIt = it->begin();
			std::cout << *pIt++ << ", " << *pIt << std::endl;
		}
	}
	// Sort the pair vector
	{
		pairs.sort(pairGreaterThan);
	}
	// Display pair list
	{
		std::cout << "===== ===== PAIRS ===== =====" << std::endl;
		for (pairVector::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			chain::iterator	pIt = it->begin();
			std::cout << *pIt++ << ", " << *pIt << std::endl;
		}
	}
	// Create main chain
	chain	mainChain;
	{
		for (pairVector::reverse_iterator Itp = pairs.rbegin(); Itp != pairs.rend(); ++Itp)
		{
			chain::iterator	it = Itp->begin(); ++it;
			mainChain.push_back(*it);
		}
	}
	// Display main chain
	{
		std::cout << "===== ===== MAINC ===== =====" << std::endl;
		for (chain::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	// Create pend chain
	chain	pendChain;
	{
		for (pairVector::reverse_iterator Itp = pairs.rbegin(); Itp != pairs.rend(); ++Itp)
			pendChain.push_back(*(Itp->begin()));
	}
	// Display pend chain
	{
		std::cout << "===== ===== PENDC ===== =====" << std::endl;
		for (chain::iterator it = pendChain.begin(); it != pendChain.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	// Insert pend elements to main chain
	{
		// Insert first pend element
		chain::reverse_iterator	pendChainEnd = pendChain.rbegin();
		chain::iterator			insertion = std::upper_bound(mainChain.begin(), mainChain.end(), *pendChainEnd);
		mainChain.insert(insertion, *pendChainEnd++);
		// Determine Jacobsthal sequence to use
		sequence	jacobsthalSeq;
		jacobsthalSeq = jacobsthalSequenceUpTo(pendChain.size());
		// Display Jacobsthal sequence used
		{
			std::cout << "===== ===== ===== ===== =====" << std::endl;
			std::cout << "Jacobsthal: ";
			for (chain::iterator it = jacobsthalSeq.begin(); it != jacobsthalSeq.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		std::list<chain::reverse_iterator>	rItArr;
		rItArr.push_back(pendChain.rbegin());
		chain::reverse_iterator	Itp = pendChainEnd;
		while (Itp != pendChain.rend())
		{
			if (!jacobsthalSeq.empty())
			{
				chain::reverse_iterator jacob = pendChain.rend();
				std::advance(jacob, -(*(jacobsthalSeq.begin()) - 1));
				unsigned long	insert = *jacob;
				chain::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), insert);
				mainChain.insert(insertion, insert);
				jacobsthalSeq.erase(jacobsthalSeq.begin());
				rItArr.push_back(jacob);
			}
			else
			{
				chain::reverse_iterator	IterEnd = pendChain.rbegin();
				while (find(rItArr.begin(), rItArr.end(), IterEnd) != rItArr.end())
					++IterEnd;
				unsigned long	insert = *IterEnd;
				chain::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), insert);
				mainChain.insert(insertion, insert);
				rItArr.push_back(IterEnd);
			}
			++Itp;
		}
	}
	// Insert straggler
	if (straggler.first == true)
	{
		chain::iterator	insertion = std::upper_bound(mainChain.begin(), mainChain.end(), straggler.second);
		mainChain.insert(insertion, straggler.second);
	}
	// Display main chain
	{
		std::cout << "===== ===== MAINC ===== =====" << std::endl;
		for (chain::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "===== ===== ===== ===== =====" << std::endl;
	}
	return (0);
}
