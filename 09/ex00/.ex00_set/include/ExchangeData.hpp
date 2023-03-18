/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeData.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:43 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 23:02:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCHANGEDATA_HPP
# define EXCHANGEDATA_HPP

# include "Date.hpp"

# include <string>
# include <exception>

class	ExchangeData
{
	private:
		const Date		_date;
		const double	_value;

	public:
		ExchangeData();
		ExchangeData(const ExchangeData &);
		~ExchangeData();
		ExchangeData & operator=(const ExchangeData &);

		ExchangeData(Date, double);
		ExchangeData(std::string);

		bool	operator<(const ExchangeData &) const;
		bool	operator>(const ExchangeData &) const;
		bool	operator<=(const ExchangeData &) const;
		bool	operator>=(const ExchangeData &) const;
		bool	operator==(const ExchangeData &) const;
		bool	operator!=(const ExchangeData &) const;

		Date	getDate() const;
		double	getValue() const;

		void	takeInput(std::string);

	class	invalidValueException: public std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
