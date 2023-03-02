/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:16:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	AForm;
class	Bureaucrat;

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm & other);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);

		PresidentialPardonForm(std::string target);

		bool	beSigned(const Bureaucrat & bureaucrat);
		bool	execute(const Bureaucrat & executor) const;

	private:
		bool				isSigned;
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		const std::string	target;
};
#endif
