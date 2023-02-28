/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:20 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 19:15:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
# define MATERIASOURCE
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & other);
		~MateriaSource();
		MateriaSource &	operator=(const MateriaSource & other);
		
		void		learnMateria(AMateria *);
		AMateria *	createMateria(const std::string & type);
	
	private:
		AMateria *	bin[4];
};
#endif
