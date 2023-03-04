/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 18:30:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include "Types.hpp"
# include "Conversions.hpp"

# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <climits>
# include <cfloat>

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
