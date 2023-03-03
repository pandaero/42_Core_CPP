/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:36:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:15:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
# define INTERN

# include <string>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		// Intern(const Intern & other);
		~Intern();
		// Intern &	operator=(const Intern & other);

		AForm *	makeForm(std::string formName, std::string formtarget);
};
#endif
