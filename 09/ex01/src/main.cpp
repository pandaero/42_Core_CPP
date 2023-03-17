/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 02:42:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

bool	isValid(const char ch)
{
	std::string valid("0123456789+-*/");

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (valid.find(ch) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	isValid(const std::string str)
{
	std::string valid("0123456789+-*/");

	if (str.length() != 1)
		return (false);

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (valid.find(str[0]) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	containsValid(char * str)
{
	std::string parse(str);
	std::string	valid(" 0123456789+-*/");

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (parse.find(valid[i]) != std::string::npos)
			return (true);
	}
	return (false);
}

// template <typename Type>
// class	StackOperations
// {
// 	private:
// 		StackOperations();
	
// 	public:
// 		~StackOperations();

// 	std::stack<Type>	reverseStack();
// };

template <typename Type>
void	reverseStack(std::stack<Type> * stack)
{
	std::stack<Type>	out;

	while (!stack->empty())
	{
		out.push(stack->top());
		stack->pop();
	}
	*stack = out;
}

typedef enum e_tokenType
{
	NUM,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	INVALID
}	t_tokenType;

t_tokenType	tokType(const char ch)
{
	switch (ch)
	{
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			return (NUM);
		case '+':
			return (PLUS);
		case '-':
			return (MINUS);
		case '*':
			return (MULTIPLY);
		case '/':
			return (DIVIDE);
		default:
			return (INVALID);
	}
}

int	tokNum(const char ch)
{
	if (isdigit(ch))
		return (ch - 48);
	return (-1);
}

typedef struct s_token
{
	s_token(const char ch): type(tokType(ch)), raw(ch), num(tokNum(ch)) {}
	t_tokenType	type;
	char		raw;
	int			num;
}				t_token;

class	InputToken
{
	private:
		const t_token	_token;

	public:
		InputToken();
		InputToken(const InputToken &);
		~InputToken();
		InputToken &	operator=(const InputToken &);

		InputToken(const char);

		t_tokenType	getType() const;
		int			getNum() const;
		char		getRaw() const;
	
	class	invalidInputException: std::exception
	{
		public:
			const char *	what() const throw();
	};
};

InputToken::InputToken():
	_token('\0')
{

}

InputToken::InputToken(const InputToken & other):
	_token(other._token.raw)
{

}

InputToken::~InputToken()
{

}

InputToken::InputToken(const char ch):
	_token(ch)
{
	if (!isValid(ch))
		throw invalidInputException();
}

InputToken &	InputToken::operator=(const InputToken & other)
{
	if (this != &other)
	{
		new (this) InputToken(other);
	}
	return (*this);
}

t_tokenType	InputToken::getType() const
{
	return (_token.type);
}

int	InputToken::getNum() const
{
	return (_token.num);
}

char	InputToken::getRaw() const
{
	return (_token.raw);
}

const char *	InputToken::invalidInputException::what() const throw()
{
	return ("Error: InputToken: invalid input.");
}

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
