/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:39:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 14:13:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <string>
# include <stack>

void	operateStack(std::stack<int> *, char);

class	RPN
{
	private:
		RPN(std::string, int);
		const std::string		_expression;
		const int				_result;

	public:
		RPN();
		RPN(const RPN &);
		~RPN();
		RPN &	operator=(const RPN &);

		RPN(std::string);

		int	getResult();

	class	invalidInputException: public std::exception
	{
		const char *	what() const throw();
	};

	class	invalidOperationException: public std::exception
	{
		const char *	what() const throw();	
	};
};
#endif
