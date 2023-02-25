/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 19:40:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE
# define CURE
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure
{
	public:
		Cure();
		Cure(const Cure & other);
		~Cure();
		Cure &	operator=(const Cure & other);
		
		std::string const & getType() const;
		Cure *				clone(const Cure & other);
		void				use(ICharacter & target);

	private:
		std::string	type;
};
#endif
