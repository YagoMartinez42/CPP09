/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:30 by samartin          #+#    #+#             */
/*   Updated: 2025/11/18 11:57:07 by samartin         ###   ########.fr       */
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
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::mapData()
{
    std::string line;
    int         lineError;

    while (std::getline (this->_csvDataFile, line))
	{
        lineError = this->validateLine(line);
        switch (lineError)
        {
            case 0:
                break;
            case 1:
                std::cout << "Sintax error in line: " << line << "\n";
                break;
            case 2:
                std::cout << "Error. Value is not a positive number: " << line << "\n";
                break;
            case 3:
                std::cout << "Error. Value too large: " << line << "\n";
                break;
        }
	}
}

int BitcoinExchange::validateLine(std::string line)
{
    // Implementation for validating a line
}
