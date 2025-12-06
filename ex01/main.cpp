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

#include "main.hpp"
#include "BitcoinExchange.hpp"


int main(int argc, char** argv)
{
	BitcoinExchange btc;

	if (argc != 2)
	{
		std::cerr << "Error: Single file argument needed." << std::endl;
		return (1);
	}
	else if (btc.loadFiles(CSV, argv[1]))
	{
		std::cerr << "Could not open file." << std::endl;
		return (1);
	}
	btc.mapData();
	btc.execute();
	return (0);
}
