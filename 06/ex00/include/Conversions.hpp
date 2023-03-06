/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 11:25:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS
# define CONVERSIONS

# include <string>
# include <cstdlib>

//Conversions from string.
char	strToChar(std::string);
int		strToInt(std::string);
float	strToFloat(std::string);
double	strToDouble(std::string);

//Conversions from char.
int		charToInt(char);
float	charToFloat(char);
double	charToDouble(char);

//Conversions from int.
char	intToChar(int);
float	intToFloat(int);
double	intToDouble(int);

//Conversions from float.
char	floatToChar(float);
int		floatToInt(float);
double	floatToDouble(float);

//Conversions from double.
char	doubleToChar(double);
int		doubleToInt(double);
float	doubleToFloat(double);

#endif
