/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:58:43 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 01:08:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
# define FIXED

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed & fixed);
		~Fixed();
		Fixed &	operator=(const Fixed & other);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					value;
		static const int	fractionalBits;
};
#endif
