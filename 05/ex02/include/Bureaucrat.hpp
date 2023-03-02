/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:36:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 22:11:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include "AForm.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class	Bureaucrat;
class	AForm;

std::ostream &	operator<<(std::ostream & outStream, const Bureaucrat & bureaucrat);

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat & other);
		~Bureaucrat();
		Bureaucrat &	operator=(const Bureaucrat & other);

		Bureaucrat(std::string name, int grade);

		std::string	getName() const;
		int			getGrade() const;
		
		void		increaseGrade();
		void		decreaseGrade();

		void		signForm(AForm & form);

		std::logic_error	GradeTooHighException();
		std::logic_error	GradeTooLowException();

	private:
		const std::string	name;
		int					grade;
};
#endif
