/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:36 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 15:01:48 by pandalaf         ###   ########.fr       */
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
		static uintptr_t	serialize(Data * ptr);
		static Data *		deserialize(uintptr_t raw);

	private:
		Serializer();
		// Serializer(const Serializer & other);
		~Serializer();
		// Serializer &	operator=(const Serializer & other);
};
#endif
