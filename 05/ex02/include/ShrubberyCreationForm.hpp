/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:59 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:16:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	AForm;
class	Bureaucrat;

void	createShrubbery(std::string target);

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &	operator=(const ShrubberyCreationForm & other);

		ShrubberyCreationForm(std::string target);

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
