/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 00:25:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE
# define CURE
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure & other);
		~Cure();
		Cure &	operator=(const Cure & other);
		
		AMateria *	clone() const;
		void		use(ICharacter & target);
};
#endif
