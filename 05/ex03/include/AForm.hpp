/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:20:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
# define FORM
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class	AForm;
class	Bureaucrat;

std::ostream &	operator<<(std::ostream & outStream, const AForm & form);

class	AForm
{
	public:
		AForm();
		AForm(const AForm & other);
		virtual ~AForm();
		AForm &	operator=(const AForm & other);

		AForm(std::string name, int signGrade, int execGrade);

		std::string	getName() const;
		bool		getSignStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		virtual bool	beSigned(const Bureaucrat & bureaucrat) = 0;
		virtual bool	execute(const Bureaucrat & executor) const = 0;

		std::logic_error	GradeTooHighException();
		std::logic_error	GradeTooLowException();

	private:
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		bool				isSigned;
};
#endif
