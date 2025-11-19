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

    std::getline(this->_csvDataFile, line); //Skip header
    while (std::getline(this->_csvDataFile, line))
	{
        if (line == "\n" || line == "\r\n")
            continue;
        lineError = this->validateCsvLine(line);
        switch (lineError)
        {
            case 0:
                break;
            case 1:
                std::cout << "Sintax error in line: " << line << "\n";
                break;
            case 2:
                std::cout << "Error. Value too large: " << line << "\n";
                break;
            case 3:
                std::cout << "Error. Value is not a positive number: " << line << "\n";
                break;
        }
	}
    std::getline(this->_argTxtFile, line); //Skip header
    while (std::getline(this->_argTxtFile, line))
	{
        if (line == "\n" || line == "\r\n")
            continue;
        lineError = this->validateInputLine(line);
        switch (lineError)
        {
            case 0:
                break;
            case 1:
                std::cout << "Sintax error in line: " << line << "\n";
                break;
            case 2:
                std::cout << "Error. Value too large: " << line << "\n";
                break;
            case 3:
                std::cout << "Error. Value is not a positive number: " << line << "\n";
                break;
        }
	}
}

int BitcoinExchange::validateCsvLine(std::string line)
{
    std::string         patron = "0000-00-00,0";
    std::istringstream  iss;
    double              d;

    for (int i = 0; i < line.length() && i < patron.length(); i++)
    {
        if (patron[i] != '0')
            if (patron[i] != line[i])
                return (1);
        else if (!std::isdigit(line[i]))
                return (1);
    }
    iss = std::istringstream(line.substr(11, -1));
    if (iss >> d && iss.eof() && d <= INT32_MAX)
        return (0);
    else if (iss >> d && d > INT32_MAX)
        return (2);
    else
        return (3);
}

int BitcoinExchange::validateInputLine(std::string line)
{

}