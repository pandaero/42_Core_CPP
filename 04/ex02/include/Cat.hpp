/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 18:31:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
# define CAT
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat & other);
		~Cat();
		Cat &	operator=(const Cat & other);

		void	makeSound() const;
		void	setIdea(std::string idea);
		void	getIdeas();

	private:
		Brain *	brain;
};
#endif
