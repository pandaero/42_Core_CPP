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

#ifndef MATERIASOURCE
# define MATERIASOURCE

class MateriaSource
{
	public:
		ICharacter();
		ICharacter(const ICharacter & other);
		~ICharacter();
		ICharacter &	operator=(const ICharacter & other);
		
		ICharacter(std::string const & name);

		std::string const & getType() const;

		virtual ICharacter *	clone() const = 0;
		virtual void		use(ICharacter & target);
};
#endif
