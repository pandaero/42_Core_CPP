/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 19:10:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
# define DOG
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog & other);
		~Dog();
		Dog &	operator=(const Dog & other);

		void	makeSound() const;
		void	setIdea(std::string idea);
		void	getIdeas();

	private:
		Brain *	brain;
};
#endif
