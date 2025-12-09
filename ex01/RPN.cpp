/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:28 by samartin          #+#    #+#             */
/*   Updated: 2025/12/06 12:05:19 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

bool RPN::calculate(std::string line)
{
	std::stack<double>	operands;
	std::string			operators = "+-*/";
	char				element;
	double				oper1;
	double				oper2;

	while (line != "")
	{
		element = line[0];
		line.erase(0, 1);
		if (element >= '0' && element <= '9')
			operands.push(element - '0');
		else if (isspace(element))
			continue;
		else if (operators.find(element) != std::string::npos)
		{
			if (operands.size() < 2)
			{
				std::cerr << "Error: Operation lacking enough operands\n";
				return (false);
			}
			oper1 = operands.top();
			operands.pop();
			oper2 = operands.top();
			operands.pop();
			switch (element)
			{
				case '+':
					operands.push(oper2 + oper1);
					break;
				case '-':
					operands.push(oper2 - oper1);
					break;
				case '*':
					operands.push(oper2 * oper1);
					break;
				case '/':
					operands.push(oper2 / oper1);
					break;
				default:
					std::cerr << "Error\n";
					return (false);
			}
		}
		else
		{
			std::cerr << "Error: Wrong element\n";
			return (false);
		}
	}
	if (operands.size() == 1)
	{
		std::cout << operands.top() << std::endl;
		return (true);
	}
	std::cerr << "Error: Operation with too many operands\n";
	return (false);
}
