/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:41:14 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 10:41:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_TPP
# define RPN_TPP

#include <stack>

template <typename Type>
void	reverseStack(std::stack<Type> * stack)
{
	std::stack<Type>	out;

	while (!stack->empty())
	{
		out.push(stack->top());
		stack->pop();
	}
	*stack = out;
}

#endif
