/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:05 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:21:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE
# define ZOMBIE
# include <string>

//Class prototypes.
class	Zombie;

//Function prototypes.
Zombie *	newZombie(std::string name);
void		randomChump(std::string name);

//Class for a zombie.
class	Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	nameZombie(std::string name);
		void	announce(void);
	private:
		std::string	name;
};
#endif
