/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/21 20:01:57 by pandalaf         ###   ########.fr       */
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
		~Animal();
		Animal &	operator=(const Animal & other);

		void	makeSound(void);

	protected:
		std::string	type;
};
#endif