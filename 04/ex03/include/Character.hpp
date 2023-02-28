/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 22:33:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
# define CHARACTER
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character();
		Character(const Character & other);
		~Character();
		Character &	operator=(const Character & other);

		Character(std::string name);

		const std::string &	getName() const;
		void				equip(AMateria * materia);
		void				unequip(int	index);
		void				use(int index, ICharacter & target);

	private:
		std::string	name;
		AMateria *	inventory[4];
};
#endif
