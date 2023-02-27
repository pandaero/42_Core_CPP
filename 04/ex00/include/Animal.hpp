/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 18:17:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL
# define ANIMAL
# include <string>

class	Animal
{
	public:
		Animal();
		Animal(const Animal & other);
		virtual	~Animal();
		Animal &	operator=(const Animal & other);

		std::string	getType(void) const;
		
		virtual	void	makeSound(void) const;

	protected:
		std::string	type;
};
#endif
