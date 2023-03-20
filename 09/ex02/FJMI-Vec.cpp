/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJMI.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:22:13 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 01:17:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <iostream>
#include <utility>
#include <vector>

typedef	std::vector<unsigned long>					sequence, chain, vectorPair;
typedef std::vector<std::vector<unsigned long> >	pairVector;

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

std::vector<unsigned long>	jacobsthalSequenceUpTo(size_t limit)
{
	std::vector<unsigned long>	sequence;
	unsigned int	jacobsthalIndex = 3;
	while (jacobsthalNumber(jacobsthalIndex) < limit)
		sequence.push_back(jacobsthalNumber(jacobsthalIndex++));
	return (sequence);
}

struct s_pairGreaterThan
{
	bool operator()(std::vector<unsigned long> a, std::vector<unsigned long> b) const
	{
		std::vector<unsigned long>::iterator	aEnd = a.end();--aEnd;
		std::vector<unsigned long>::iterator	bEnd = b.end();--bEnd;
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
	// in.push_back(123);
	in.push_back(11);
	in.push_back(14);

	// Display input list
	{
		std::cout << "===== ===== INPUT ===== =====" << std::endl;
		for (size_t i = 0; i < in.size(); ++i)
		{	
			if (i != in.size() - 1)
				std::cout << in[i] << " ";
			else
				std::cout << in[i];
			if (i % 2 == 1)
				std::cout << "| ";
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
		for (size_t i = 0; i < pairs.size(); ++i)
			std::cout << pairs[i][0] << ", " << pairs[i][1] << std::endl;
	}
	// Sort each pair's elements
	for (pairVector::iterator It = pairs.begin(); It != pairs.end(); ++It)
	{
		vectorPair::iterator	ItpBeg = It->begin();
		vectorPair::iterator	ItpEnd = It->end();
		if (It->size() > 1)
			std::sort(ItpBeg, ItpEnd);
	}
	// Display pair list
	{
		std::cout << "===== ===== PAIRS ===== =====" << std::endl;
		for (size_t i = 0; i < pairs.size(); ++i)
			std::cout << pairs[i][0] << ", " << pairs[i][1] << std::endl;
	}
	// Sort the pair vector
	{
		std::sort(pairs.begin(), pairs.end(), pairGreaterThan);
	}
	// Display pair list
	{
		std::cout << "===== ===== PAIRS ===== =====" << std::endl;
		for (size_t i = 0; i < pairs.size(); ++i)
			std::cout << pairs[i][0] << ", " << pairs[i][1] << std::endl;
	}
	// Create main chain
	chain	mainChain;
	{
		for (pairVector::reverse_iterator Itp = pairs.rbegin(); Itp != pairs.rend(); ++Itp)
			mainChain.push_back((*Itp)[1]);
	}
	// Display main chain
	{
		std::cout << "===== ===== MAINC ===== =====" << std::endl;
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			if (i != mainChain.size() - 1)
				std::cout << mainChain[i] << " ";
			else
				std::cout << mainChain[i];
		}
		std::cout << std::endl;
	}
	// Create pend chain
	chain	pendChain;
	{
		for (pairVector::reverse_iterator Itp = pairs.rbegin(); Itp != pairs.rend(); ++Itp)
			pendChain.push_back((*Itp)[0]);
	}
	// Display pend chain
	{
		std::cout << "===== ===== PENDC ===== =====" << std::endl;
		for (size_t i = 0; i < pendChain.size(); ++i)
		{
			if (i != pendChain.size() - 1)
				std::cout << pendChain[i] << " ";
			else
				std::cout << pendChain[i];
		}
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
			for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
			{
				if (i != jacobsthalSeq.size() - 1)
					std::cout << jacobsthalSeq[i] << " ";
				else
					std::cout << jacobsthalSeq[i];
			}
			std::cout << std::endl;
		}
		std::vector<chain::reverse_iterator>	rItArr;
		rItArr.push_back(pendChain.rbegin());
		chain::reverse_iterator	Itp = pendChainEnd;
		while (Itp != pendChain.rend())
		{
			if (!jacobsthalSeq.empty())
			{
				chain::reverse_iterator jacob = pendChain.rend();
				std::advance(jacob, -(*(jacobsthalSeq.begin()) - 1));
				unsigned long	insert = *jacob;
				// unsigned long	insert = pendChain[*(jacobsthalSeq.begin()) - 1];
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
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			if (i != mainChain.size() - 1)
				std::cout << mainChain[i] << " ";
			else
				std::cout << mainChain[i];
		}
		std::cout << std::endl;
		std::cout << "===== ===== ===== ===== =====" << std::endl;
	}
	return (0);
}
