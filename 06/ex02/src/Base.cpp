/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 20:41:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base *	generate(void)
{
	Base * obj;

	switch (time(NULL) % 3)
	{
		case 0:
			obj = new A;
			std::cout << "Generated class A obj." << std::endl;
			break;
		case 1:
			obj = new B;
			std::cout << "Generated class B obj." << std::endl;
			break;
		case 2:
			obj = new C;
			std::cout << "Generated class C obj." << std::endl;
			break;
	}
	return (obj);	
}

void	identify(Base * p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "Object is of class A." << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "Object is of class B." << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "Object is of class C." << std::endl;
	else
		std::cout << "Object is unidentified." << std::endl;
}

void	identify(Base & p)
{
	try
	{
		Base	obj;
		obj = dynamic_cast<A &>(p);
		std::cout << "Object is of class A." << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		Base	obj;
		obj = dynamic_cast<B &>(p);
		std::cout << "Object is of class B." << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		Base	obj;
		obj = dynamic_cast<C &>(p);
		std::cout << "Object is of class C." << std::endl;
	}
	catch(const std::exception& e){}
}
