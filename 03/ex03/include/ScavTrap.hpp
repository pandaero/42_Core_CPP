/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:26:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 09:13:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP
# define SCAVTRAP
# include <string>
# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap & other);
		~ScavTrap(void);
		ScavTrap &	operator=(const ScavTrap & other);
		
		ScavTrap(const std::string name);
		void	guardGate(void);
		void	attack(const std::string & target);
};
#endif
