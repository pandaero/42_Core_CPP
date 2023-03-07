/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/07 13:32:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.tpp"

#include <list>

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::cout << "Subject Test" << std::endl << std::endl;
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		std::cout << "Pushed 5, then 17..." << std::endl;
		std::cout << "Top value: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Popped stack..." << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << std::endl << "Bottom" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Top" << std::endl << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::cout << "List Test" << std::endl << std::endl;
		std::list<int> listy;

		listy.push_back(5);
		listy.push_back(17);
		
		std::cout << "Pushed 5, then 17..." << std::endl;
		std::cout << "Top value: " << listy.back() << std::endl;
		listy.pop_back();
		std::cout << "Popped last..." << std::endl;
		std::cout << "Stack size: " << listy.size() << std::endl << std::endl;
		listy.push_back(3);
		listy.push_back(5);
		listy.push_back(737);
		listy.push_back(0);
		
		std::list<int>::iterator it = listy.begin();
		std::list<int>::iterator ite = listy.end();

		++it;
		--it;
		std::cout << "Bottom" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Top" << std::endl << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::cout << "Iterator Test" << std::endl << std::endl;

		MutantStack<int>	mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		std::cout << "Stack forwards: " << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl << "Stack backwards: " << std::endl;
		it--;
		while (it != mstack.begin() - 1)
		{
			std::cout << *it << " ";
			--it;
		}
		std::cout << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;
	
	{
		std::cout << "Reverse Iterator Test" << std::endl << std::endl;

		MutantStack<int>	mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);

		MutantStack<int>::reverse_iterator	rit = mstack.rend() - 1;
		MutantStack<int>::reverse_iterator	rite = mstack.rbegin();

		std::cout << "Stack forwards: " << std::endl;
		while (rit != rite - 1)
		{
			std::cout << *rit << " ";
			--rit;
		}
		std::cout << std::endl << "Stack backwards: " << std::endl;

		rit = mstack.rend();

		while (rite != rit)
		{
			std::cout << *rite << " ";
			rite++;
		}
		std::cout << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}