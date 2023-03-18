/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:05:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 21:23:50 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "ExchangeData.hpp"

# include <set>
# include <exception>

class BitcoinExchange
{
	private:
		std::set<ExchangeData>	_exchangeHistory;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		~BitcoinExchange();
		BitcoinExchange &	operator=(const BitcoinExchange &);

		BitcoinExchange(std::string);

		double	findValue(Date) const;

	class	invalidFileException:	public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	datePredatesException:	public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	dateExceedsException:	public std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
