/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:38:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 14:13:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

void	operateStack(std::stack<int> * stack, char oprtor)
{
	int	first = stack->top(); stack->pop();
	int second = stack->top(); stack->pop();
	switch (oprtor)
	{
		case '+':
			stack->push(second + first);
			break;
		case '-':
			stack->push(second - first);
			break;
		case '*':
			stack->push(second * first);
			break;
		case '/':
			stack->push(second / first);
			break;
		default:
			throw RPN::invalidOperationException();
			break;
	}
}

RPN::RPN(std::string expression, int result):
	_expression(expression),
	_result(result)
{

}

RPN::RPN():
	_expression(""),
	_result(0)
{

}

RPN::RPN(const RPN & other):
	_expression(other._expression),
	_result(other._result)
{

}

RPN::~RPN()
{

}

RPN &	RPN::operator=(const RPN & other)
{
	if (this != &other)
		new (this) RPN(other._expression);
	return (*this);
}

RPN::RPN(std::string expression):
	_expression(""),
	_result(0)
{
	std::string	valid(" 0123456789+-*/");
	std::stack<int>	operationStack;
	for (std::string::iterator it = expression.begin(); it != expression.end(); ++it)
	{
		if (valid.find(*it) == std::string::npos)
			throw invalidInputException();
		if (*it == ' ')
			continue;
		if (*it >= '0' && *it <= '9')
		{
			std::string::iterator	itcpy = it; ++itcpy;
			if (*itcpy >= '0' && *itcpy <= '9')
				throw invalidOperationException();
			operationStack.push(*it - '0');
		}
		else if (operationStack.size() > 1)
		{
			std::string::iterator	itcpy = it; ++itcpy;
			if (*itcpy >= '0' && *itcpy <= '9')
				throw invalidOperationException();
			operateStack(&operationStack, *it);
		}
		else
			throw invalidOperationException();
	}
	new (this) RPN(expression, operationStack.top());
}

int	RPN::getResult()
{
	return (_result);
}

const char *	RPN::invalidInputException::what() const throw()
{
	return ("Error: RPN: invalid input.");
}

const char *	RPN::invalidOperationException::what() const throw()
{
	return ("Error: RPN: invalid operation.");
}
