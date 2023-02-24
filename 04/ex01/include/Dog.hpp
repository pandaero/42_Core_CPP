/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 15:42:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
# define DOG
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog & other);
		~Dog();
		Dog &	operator=(const Dog & other);

	private:
		Brain *	brain;
};
#endif
