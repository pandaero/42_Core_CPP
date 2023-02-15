/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:07:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 14:24:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iostream>

typedef struct s_vector 
{
	float	x_comp;
	float	y_comp;
}			vector;

static vector	make_vector(Point first, Point second)
{
	vector	vec;
	vec.x_comp = second.getx().toFloat() - first.getx().toFloat();
	vec.y_comp = second.gety().toFloat() - first.gety().toFloat();
	return (vec);
}

static	float	dot_product(vector one, vector two)
{
	return (one.x_comp * two.x_comp + one.y_comp * two.y_comp);
}

// Barycentric technique based on Point inside P = a + u * (c - a) + v * (b - a).
//Function determines whether a point is within the triangle with vertices a,b,c.
bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	vector	toc = make_vector(a, c);
	vector	tob = make_vector(a, b);
	vector	top = make_vector(a, point);

	float	dotcc = dot_product(toc, toc);
	float	dotcb = dot_product(toc, tob);
	float	dotcp = dot_product(toc, top);
	float	dotbb = dot_product(tob, tob);
	float	dotbp = dot_product(tob, top);

	float	denom = 1 / (dotcc * dotbb - dotcb * dotcb);
	float	u = (dotbb * dotcp - dotcb * dotcp) * denom;
	float	v = (dotcc * dotbp - dotcb * dotcp) * denom;

	if  ((u >= 0) && (v >= 0) && (u + v < 1))
	{
		if (point == a || point == b || point == c)
			return (false);
		else
			return (true);
	}
	else
		return (false);
}
