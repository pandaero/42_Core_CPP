/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 14:24:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 2.5f);
	Point	d;
	Point	p_in(0.5f, 0.5f);
	Point	p_out(-0.5f, 0.5f);
	Point	p_vert(0.0f, 0.0f);

	std::cout << "Point a: (" << a.getx() << ", " << a.gety() << ")\n";
	std::cout << "Point b: (" << b.getx() << ", " << b.gety() << ")\n";
	std::cout << "Point c: (" << c.getx() << ", " << c.gety() << ")\n";
	std::cout << "Point p in  : (" << p_in.getx() << ", " << p_in.gety() << ")\n";
	std::cout << "Point p out : (" << p_out.getx() << ", " << p_out.gety() << ")\n";
	std::cout << "Point p vert: (" << p_vert.getx() << ", " << p_vert.gety() << ")\n";
	std::cout << "p_ver == a: " << (p_vert == a) << std::endl;
	d = a;
	std::cout << "d = a" << std::endl;
	std::cout << "Point d: (" << a.getx() << ", " << a.gety() << ")\n";
	std::cout << "Point in  : " << bsp(a, b, c, p_in) << std::endl;
	std::cout << "Point out : " << bsp(a, b, c, p_out) << std::endl;
	std::cout << "Point vert: " << bsp(a, b, c, p_vert) << std::endl;

	return (0);
}
