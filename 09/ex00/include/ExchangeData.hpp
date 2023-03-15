/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeData.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:43 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 12:52:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCHANGEDATA_HPP
# define EXCHANGEDATA_HPP

# include <string>

bool	isDateFormat(std::string);

class	ExchangeData
{
	private:
		const std::string	_date;
		const double		_value;

	public:
		ExchangeData();
		ExchangeData(const ExchangeData &);
		~ExchangeData();
		ExchangeData & operator=(const ExchangeData &);

		ExchangeData(std::string, double);
		ExchangeData(std::string);

	class	invalidDateException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidValueException: public std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
