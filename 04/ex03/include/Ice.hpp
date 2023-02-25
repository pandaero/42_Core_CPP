/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 19:15:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE
# define ICE
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice
{
	public:
		Ice();
		Ice(const Ice & other);
		~Ice();
		Ice &	operator=(const Ice & other);
		
		std::string const & getType() const;
		Ice *				clone(const Ice & other);
		void				use(ICharacter & target);

	private:
		std::string	type;
};
#endif
