/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:06:41 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 03:10:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKOPERATIONS_HPP
# define STACKOPERATIONS_HPP

# include <stack>

int	addStack(int start, std::stack<int>);

int	subtractStack(int start, std::stack<int>);

int	multiplyStack(int start, std::stack<int>);

int	divideStack(int start, std::stack<int>);

#endif
