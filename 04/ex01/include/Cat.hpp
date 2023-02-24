/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 15:42:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
# define CAT
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat & other);
		~Cat();
		Cat &	operator=(const Cat & other);

	private:
		Brain *	brain;
};
#endif
