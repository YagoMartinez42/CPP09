/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/11/18 11:52:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	BitcoinExchange btc;

	if (argc != 2)
	{
		std::cout << "Error: Single file argument needed.";
		return (1);
	}
	else
	{
		if (btc.loadFiles(CSV, argv[1]));
			return (1);
	}

	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|    Test from subject    |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		
			

	}
	return (0);
}
