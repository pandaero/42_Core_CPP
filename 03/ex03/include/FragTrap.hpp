/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:38:13 by pandalaf          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/16 13:17:48 by pandalaf         ###   ########.fr       */
=======
/*   Updated: 2023/02/17 09:13:46 by pandalaf         ###   ########.fr       */
>>>>>>> e0cb34e00e08571ed2a2b0d2ffb36242d4379b5d
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP
# include "ScavTrap.hpp"

class	FragTrap: virtual public ClapTrap
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
