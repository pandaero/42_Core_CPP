/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputToken.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:44:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 03:19:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTTOKEN_HPP
# define INPUTTOKEN_HPP

# include <string>
# include <exception>

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
