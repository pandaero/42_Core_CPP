/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 19:16:21 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include "../include/RPN.tpp"

#include <iostream>
#include <sstream>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}

	if (!containsValid(argv[1]))
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}

	{
		std::string				inputStr(argv[1]);
		std::stack<InputToken>	expressionStack;
		
		try
		{
			std::stringstream	inputStream(inputStr);

			std::string	buffer;
			while (getline(inputStream, buffer, ' '))
			{
				if (!isValid(buffer))
				{
					std::cerr << "Error: invalid input" << std::endl;
					return (1);
				}
				InputToken	check(buffer[0]);
				expressionStack.push(check);
			}
		}
		catch (std::exception & exc)
		{
			std::cerr << "Error: invalid input." << std::endl;
			return (1);
		}

		reverseStack(&expressionStack);
		
		std::stack<int>	operationStack;
		
		int	i = 0;
		while (!expressionStack.empty())
		{
			InputToken	tok = expressionStack.top();
	
			if ((i == 1 && tok.getType() != NUM) || \
				(i > 0 && tok.getType() != NUM && operationStack.size() == 1))
			{
				std::cerr << "Error: invalid operation." << std::endl;
				return (1);
			}

			switch (tok.getType())
			{
				case NUM:
					operationStack.push(tok.getNum());
					break;
				case PLUS:
					operateStack(&operationStack, PLUS);
					break;
				case MINUS:
					operateStack(&operationStack, MINUS);
					break;
				case MULTIPLY:
					operateStack(&operationStack, MULTIPLY);
					break;
				case DIVIDE:
					operateStack(&operationStack, DIVIDE);
					break;
				default:
					std::cerr << "Error: invalid argument/operand" << std::endl;
					return (1);
			}
			expressionStack.pop();
			++i;
		}
		std::cout << operationStack.top() << std::endl;
	}

	return (0);
}
