/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 14:06:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL
# define WRONGANIMAL
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal & other);
		~WrongAnimal();
		WrongAnimal &	operator=(const WrongAnimal & other);

		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	type;
};
#endif
