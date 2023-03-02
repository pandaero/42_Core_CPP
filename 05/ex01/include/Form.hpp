/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 20:54:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
# define FORM
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class	Form;
class	Bureaucrat;

std::ostream &	operator<<(std::ostream & outStream, const Form & form);

class	Form
{
	public:
		Form();
		Form(const Form & other);
		~Form();
		Form &	operator=(const Form & other);

		Form(std::string name, int signGrade, int execGrade);

		std::string	getName() const;
		bool		getSignStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		bool		beSigned(const Bureaucrat & bureaucrat);

		std::logic_error	GradeTooHighException();
		std::logic_error	GradeTooLowException();

	private:
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		bool				isSigned;
};
#endif
