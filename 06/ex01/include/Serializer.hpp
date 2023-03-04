/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:36 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 20:02:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER
# define SERIALIZER

# include <cstdint>
# include <sstream>
# include <string>

typedef struct 
{
	char	a;
	int		b;
}			Data;

class	Serializer
{
	public:
		Serializer();
		// Serializer(const Serializer & other);
		~Serializer();
		// Serializer &	operator=(const Serializer & other);

		uintptr_t	serialize(Data * ptr);
		Data *		deserialize(uintptr_t raw);
};
#endif
