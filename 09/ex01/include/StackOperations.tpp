/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackOperations.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:07:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 03:20:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKOPERATIONS_TPP
# define STACKOPERATIONS_TPP

# include <stack>

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
