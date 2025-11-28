/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 14:09:27 by samartin          #+#    #+#             */
/*   Updated: 2025-11-21 14:09:27 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange()
{
	this->_csvDataFile.close();
	this->_argTxtFile.close();
}

int BitcoinExchange::loadFiles(const char* dataSetFile, const char* evalSetFile)
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
	std::string			line;
	std::istringstream	iss;
	double				d;

	std::getline(this->_csvDataFile, line); //Skip header
	while (std::getline(this->_csvDataFile, line))
	{
		if (line == "\n" || line == "\r\n")
			continue;
		if (this->validateLine(line, "0000-00-00,", true))
		{
			iss.clear();
			iss.str(line.substr(11));
			iss >> d;
			this->_dataSet[line.substr(0,10)] = d;
		}
	}
std::cout << std::endl;
	std::getline(this->_argTxtFile, line); //Skip header
	while (std::getline(this->_argTxtFile, line))
	{
		if (line == "\n" || line == "\r\n")
			continue;
		if (this->validateLine(line, "0000-00-00 | ", false))
		{
			iss.clear();
			iss.str(line.substr(13));
			iss >> d;
			this->_evalSet[line.substr(0,10)] = d;
		}
	}
std::cout << std::endl;
}

void BitcoinExchange::showData()
{
	std::ofstream aFile;

	for(std::map<std::string, double>::iterator it = this->_dataSet.begin(); it != this->_dataSet.end(); it++)
		std::cout << (*it).first << " / " << (*it).second << "\n";
	std::cout << std::endl;
}

bool BitcoinExchange::validateLine(const std::string line, const std::string pattern, const bool smode) const
{
	std::istringstream	iss;
	struct tm			dumpDate;
	char*				strPntr;
	double				d;
	size_t			 	i;

	for (i = 0; i < line.length() && i < pattern.length(); i++)
	{
		if (pattern[i] != '0')
		{
			if (pattern[i] != line[i])
			{
				std::cerr << "Syntax error in line: " << line << "\n";
				return (false);
			}
		}
		else if (!std::isdigit(line[i]))
		{
			std::cerr << "Syntax error in line: " << line << "\n";
			return (false);
		}
	}
	strPntr = strptime(line.substr(10).c_str(), "%Y-%m-%d", &dumpDate);
	if (strPntr && *strPntr != '\0')
	{
		std::cerr << "Error. Not a valid date: " << line << "\n";
		return (false);
	}
	iss.str(line.substr(i));
	if (iss >> d && iss.eof() && !((d < 0) * smode) && d <= 2147483647) //INT32 Max
		return (true);
	else if (iss >> d && d > 2147483647)
	{
		std::cerr << "Error. Value too large: " << line << "\n";
		return (false);
	}
	else if (smode && iss >> d && d < 0)
	{
		std::cerr << "Error. Value is not a positive number: " << line << "\n";
		return (false);
	}
	else
		std::cerr << "Unhandled Error: " << line << "\n";
	return (0);
}
