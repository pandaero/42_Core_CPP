/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:36 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 20:35:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE
# define BASE

# include <ctime>
# include <iostream>
# include <unistd.h>

class	Base
{
	public:
		virtual	~Base() {}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

#endif
