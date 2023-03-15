/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:57:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 22:03:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <string>
# include <ostream>
# include <exception>

bool	isDateFormat(std::string);

class	Date;

std::ostream &	operator<<(std::ostream & outStream, const Date & date);

class	Date
{
	private:
		const int	_year;
		const int	_month;
		const int	_day;

	public:
		Date();
		Date(const Date &);
		~Date();
		Date &	operator=(const Date &);

		Date(int, int, int);
		Date(std::string);

		bool	operator<(const Date &) const;
		bool	operator>(const Date &) const;
		bool	operator<=(const Date &) const;
		bool	operator>=(const Date &) const;
		bool	operator==(const Date &) const;
		bool	operator!=(const Date &) const;

		Date	operator++();
		Date &	operator++(int);
		Date	operator--();
		Date &	operator--(int);

		int	getYear() const;
		int	getMonth() const;
		int	getDay() const;

		std::string	str();
		void		takeStr(std::string);

	class	invalidDateException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidYearException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidMonthException: public std::exception
	{
		public:
			const char *	what() const throw();
	};

	class	invalidDayException: public std::exception
	{
		public:
			const char *	what() const throw();
	};
};
#endif
