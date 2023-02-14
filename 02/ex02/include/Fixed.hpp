/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:48:00 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 20:50:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
# define FIXED
# include <ostream>

//Class represents a fixed-point number with 24 bits for intpart and 8 bits for fracpart.
class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed & fixed);
		~Fixed();
		Fixed &	operator=(const Fixed & other);

		Fixed(const int value);
		Fixed(const float value);
		bool	operator>(const Fixed & other);
		bool	operator<(const Fixed & other);
		bool	operator>=(const Fixed & other);
		bool	operator<=(const Fixed & other);
		bool	operator==(const Fixed & other);
		bool	operator!=(const Fixed & other);
		Fixed	operator+(const Fixed & other);
		Fixed	operator-(const Fixed & other);
		Fixed	operator*(const Fixed & other);
		Fixed	operator/(const Fixed & other);
		Fixed &	operator++();
		Fixed	operator++(int);
		Fixed &	operator--();
		Fixed	operator--(int decrements);

		float			toFloat(void) const;
		int				toInt(void) const;
		int				getRawBits(void) const;
		void			setRawBits(const int raw);

	private:
		int					value;
		static const int	fractionalBits;
};
std::ostream &	operator<<(std::ostream & outStream, const Fixed & fixed);
#endif
