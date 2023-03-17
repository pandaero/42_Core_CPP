/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:39:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 10:40:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <exception>

int	addStack(int start, std::stack<int>);

int	subtractStack(int start, std::stack<int>);

int	multiplyStack(int start, std::stack<int>);

int	divideStack(int start, std::stack<int>);

bool	isValid(const char);

bool	isValid(const std::string &);

bool	containsValid(char *);

typedef enum e_tokenType
{
	NUM,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	INVALID
}	t_tokenType;

t_tokenType	tokType(const char);

int	tokNum(const char);

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
#endif
