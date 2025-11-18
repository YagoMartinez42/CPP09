/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:30 by samartin          #+#    #+#             */
/*   Updated: 2025/11/18 11:52:30 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::loadFiles(char* dataSetFile, char* evalSetFile)
{
    try
    {
        this->_csvDataFile.open(dataSetFile);
        this->_argTxtFile.open(evalSetFile);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}

void BitcoinExchange::mapData()
{
    // Implementation for mapping data
    /*while (std::getline (csvData, myStr))
	{

	}*/
}

void BitcoinExchange::validateLine(std::string line)
{
    // Implementation for validating a line
}
