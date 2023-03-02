/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:36:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 17:40:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include <string>
# include <iostream>
# include <stdexcept>

class	Bureaucrat;

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

		std::invalid_argument	GradeTooHighException();
		std::invalid_argument	GradeTooLowException();

	private:
		const std::string	name;
		int					grade;
};
#endif
