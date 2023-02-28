/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 00:27:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
# define AMATERIA
# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(const AMateria & other);
		virtual	~AMateria();
		AMateria &	operator=(const AMateria & other);
		
		AMateria(const std::string & type);

		std::string const & getType() const;

		virtual	AMateria *	clone() const = 0;
		virtual	void		use(ICharacter & target);

	protected:
		std::string	type;
};
#endif
