/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:06 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 14:17:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT
# define POINT

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const Point & point);
		~Point(void);
		Point & operator=(const Point & other);

		Point(const float xco, const float yco);
		bool	operator==(const Point & other) const;

		Fixed	getx(void) const;
		Fixed	gety(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

bool	bsp(Point a, Point b, Point c, Point point);

#endif
