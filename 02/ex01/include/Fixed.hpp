/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:48:00 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 10:26:53 by pandalaf         ###   ########.fr       */
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
