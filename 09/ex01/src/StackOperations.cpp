/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:04:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 03:20:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StackOperations.hpp"
#include "../include/StackOperations.tpp"

int	addStack(int start, std::stack<int> stack)
{
	while (!stack.empty())
	{
		start += stack.top();
		stack.pop();
	}
	return (start);
}

int	subtractStack(int start, std::stack<int> stack)
{
	while (!stack.empty())
	{
		start -= stack.top();
		stack.pop();
	}
	return (start);
}

int	multiplyStack(int start, std::stack<int> stack)
{
	while (!stack.empty())
	{
		start *= stack.top();
		stack.pop();
	}
	return (start);
}

int	divideStack(int	start, std::stack<int> stack)
{
	while (!stack.empty())
	{
		start /= stack.top();
		stack.pop();
	}
	return (start);
}
