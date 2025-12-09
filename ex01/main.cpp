/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/12/05 14:02:06 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Single operation argument needed." << std::endl;
		return (1);
	}
	RPN::calculate(argv[1]);
	return (0);
}
