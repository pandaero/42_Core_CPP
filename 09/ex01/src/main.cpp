/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 13:57:55 by pandalaf         ###   ########.fr       */
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
		
		int	value;
		int	i = 0;
		while (!expressionStack.empty())
		{
			InputToken	tok = expressionStack.top();
	
			if (i == 1 && tok.getType() != NUM)
			{
				std::cerr << "Error: invalid operation." << std::endl;
				return (1);
			}


			switch (tok.getType())
			{
				case NUM:
					if (!i)
						value = tok.getNum();
					else
						operationStack.push(tok.getNum());
					expressionStack.pop();
					break;
				case PLUS:
					value = addStack(value, operationStack);
					for (size_t j = 0; j < operationStack.size(); ++j)
					{
						expressionStack.pop();
						operationStack.pop();
					}
					break;
				case MINUS:
					value = subtractStack(value, operationStack);
					for (size_t j = 0; j < operationStack.size(); ++j)
					{
						expressionStack.pop();
						operationStack.pop();
					}
					break;
				case MULTIPLY:
					value = multiplyStack(value, operationStack);
					for (size_t j = 0; j < operationStack.size(); ++j)
					{
						expressionStack.pop();
						operationStack.pop();
					}
					break;
				case DIVIDE:
					value = divideStack(value, operationStack);
					for (size_t j = 0; j < operationStack.size(); ++j)
					{
						expressionStack.pop();
						operationStack.pop();
					}
					break;
				default:
					std::cerr << "Error: invalid argument/operand" << std::endl;
					return (1);
			}
			++i;
		}
		std::cout << value << std::endl;
	}

	return (0);
}
