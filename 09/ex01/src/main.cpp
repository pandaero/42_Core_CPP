/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 20:40:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <stack>

#include <unistd.h>

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
	if (argc < 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}

	{
		std::stack<InputToken>	expr;
		
		for (int i = argc - 1; i > 0; --i)
		{
			expr.push(InputToken((*argv[i])));
		}
		
		std::stack<int>	opStack;
		
		int	value;
		int i = 0;
		while (!expr.empty())
		{
			InputToken		tok = expr.top();
	
			switch (tok.getType())
			{
				case NUM:
					if (!i)
						value = tok.getNum();
					else
						opStack.push(tok.getNum());
					expr.pop();
					break;
				case PLUS:
					value = addStack(value, opStack);
					for (size_t j = 0; j < opStack.size(); ++j)
						expr.pop();
					break;
				case MINUS:
					value = subtractStack(value, opStack);
					for (size_t j = 0; j < opStack.size(); ++j)
						expr.pop();
					break;
				case MULTIPLY:
					value = multiplyStack(value, opStack);
					for (size_t j = 0; j < opStack.size(); ++j)
						expr.pop();
					break;
				case DIVIDE:
					value = divideStack(value, opStack);
					for (size_t j = 0; j < opStack.size(); ++j)
						expr.pop();
					break;
				default:
					std::cerr << "Error: invalid argument/operand" << std::endl;
					return (1);
			}
			std::cout << value << std::endl;
			++i;
		}
		std::cout << value << std::endl;
	}

	return (0);
}
