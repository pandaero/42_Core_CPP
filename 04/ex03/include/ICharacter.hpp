/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 19:15:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER
# define ICHARACTER
# include "AMateria.hpp"

class ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual	std::string const &	getName() const = 0;
		virtual	void				equip(AMateria * materia) = 0;
		virtual	void				unequip(int index) = 0;
		virtual	void				use(int index, ICharacter & target) = 0;
};
#endif
