/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 23:43:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	AForm;
class	Bureaucrat;

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm & other);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);

		RobotomyRequestForm(std::string target);

		bool	beSigned(const Bureaucrat & bureaucrat);
		void	execute(const Bureaucrat & executor) const;

	private:
		bool				isSigned;
		const std::string	name;
		const int			signGrade;
		const int			execGrade;
		const std::string	target;

		static int	robotomyCount;
};
#endif
