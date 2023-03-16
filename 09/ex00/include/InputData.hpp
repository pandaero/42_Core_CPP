/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:07:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 01:30:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTDATA_HPP
# define INPUTDATA_HPP

# include "Date.hpp"

# include <string>
# include <exception>

class					InputData;

InputData	*readInput(std::string);

class	InputData
{
	private:
		Date		_date;
		double		_value;
		std::string	_outLine;

	public:
		InputData();
		InputData(const InputData &);
		~InputData();
		InputData &	operator=(const InputData&);

		InputData(Date, double, std::string);

	class	invalidFileException: std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidDateInputException: std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	negativeValueException: std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	largeValueException: std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
