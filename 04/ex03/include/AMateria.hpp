/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 20:04:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
# define AMATERIA
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	public:
		~AMateria();
		AMateria &	operator=(const AMateria & other);
		
		AMateria(std::string const & type);

		std::string const & getType() const;

		virtual AMateria *	clone() const = 0;
		virtual void		use(ICharacter & target);

	protected:
		AMateria();
		AMateria(const AMateria & other);

};
#endif
