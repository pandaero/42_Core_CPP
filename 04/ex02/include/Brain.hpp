/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:53:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 14:14:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN
# define BRAIN
# include <string>

class	Brain
{
	public:
		Brain();
		Brain(const Brain & other);
		~Brain();
		Brain &	operator=(const Brain & other);

		void	setIdea(std::string idea);
		void	getIdeas();
	
	private:
		std::string	ideas[100];
};
#endif
