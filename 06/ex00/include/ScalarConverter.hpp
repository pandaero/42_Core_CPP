/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 15:21:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include <string>

class	ScalarConverter
{
	public:
		ScalarConverter();
		// ScalarConverter(const ScalarConverter & other);
		~ScalarConverter();
		// ScalarConverter &	operator=(const ScalarConverter & other);

		static void	convert(std::string literal);
};
#endif
