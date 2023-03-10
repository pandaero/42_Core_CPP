/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:38:13 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 10:44:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP
# include "ScavTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap & other);
		~FragTrap(void);
		FragTrap &	operator=(const FragTrap & other);

		FragTrap(const std::string name);
		void	highFivesGuys(void);
};
#endif
