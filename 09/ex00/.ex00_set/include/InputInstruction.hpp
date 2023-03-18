/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputInstruction.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:18:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 21:08:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INPUTINSTRUCTION_HPP
# define INPUTINSTRUCTION_HPP

# include "Date.hpp"

# include <string>
# include <exception>

class	InputInstruction
{
	private:
		const Date			_date;
		const double		_value;
		const std::string	_error;

	public:
		InputInstruction();
		InputInstruction(const InputInstruction &);
		~InputInstruction();
		InputInstruction & operator=(const InputInstruction &);

		InputInstruction(Date, double, std::string);
		InputInstruction(Date, double);
		InputInstruction(std::string);

		Date		getDate() const;
		double		getValue() const;
		std::string	getError() const;

		void	takeInput(std::string);

	class	invalidInputException: public std::exception
	{
		public:
			const char *	what() const throw();
	};
	
	class	negValueException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	largeValueException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidDateException: public std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
