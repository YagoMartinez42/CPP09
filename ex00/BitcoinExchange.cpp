/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:09:27 by samartin          #+#    #+#             */
/*   Updated: 2025/12/05 13:39:33 by samartin         ###   ########.fr       */
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
		this->_csvDataFile.open(dataSetFile, std::ifstream::out);
		this->_argTxtFile.open(evalSetFile, std::ifstream::out);
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
		if (this->validateLine(line, "0000-00-00,"))
		{
			iss.clear();
			iss.str(line.substr(11));
			iss >> d;
			this->_dataSet[line.substr(0,10)] = d;
		}
	}
}

void BitcoinExchange::execute()
{
	std::string								line;
	std::string								date;
	std::istringstream						iss;
	std::map<std::string, double>::iterator it;
	double									d;

	std::getline(this->_argTxtFile, line); //Skip header
	while (std::getline(this->_argTxtFile, line))
	{
		if (line == "\n" || line == "\r\n")
			continue;
		if (this->validateLine(line, "0000-00-00 | "))
		{
			date = line.substr(0,10);
			iss.clear();
			iss.str(line.substr(13));
			iss >> d;
			if (this->_dataSet.find(date) != this->_dataSet.end())
				std::cout << date << " => " << d << " = " << this->_dataSet[date] * d << "\n";
			else
            {
				it = this->_dataSet.upper_bound(date);
                if (it != this->_dataSet.begin())
                {
                    it--;
                    std::cout << date << " => " << d << " = " << it->second * d << "\n";
                }
                else
                    std::cout << "Error: No available data for date " << date << "\n";
            }
		}
	}
	std::cout << std::endl;
}

void BitcoinExchange::showData() const
{
	std::ofstream aFile;

	aFile.open("out.txt");
	for(std::map<std::string, double>::const_iterator it = this->_dataSet.begin(); it != this->_dataSet.end(); it++)
		aFile << (*it).first << " / " << (*it).second << "\n";
	aFile << std::endl;
	aFile.close();
}

bool BitcoinExchange::validateLine(const std::string line, const std::string pattern) const
{
	std::istringstream	iss;
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
	if (!this->validateDate(line.substr(0,10)))
	{
		std::cerr << "Error. Not a valid date: " << line << "\n";
		return (false);
	}
	iss.clear();
	iss.str(line.substr(i));
	if (!(iss >> d))
	{
		std::cerr << "Error. Not a numeric value: " << line << "\n";
		return (false);
	}
	if (d > 2147483647)
	{
		std::cerr << "Error. Value too large: " << line << "\n";
		return (false);
	}
	else if (d < 0)
	{
		std::cerr << "Error. Value is not a positive number: " << line << "\n";
		return (false);
	}
	else if (iss.eof() && d <= 2147483647) //INT32 Max
		return (true);
	else
		std::cerr << "Unhandled Error: " << line << "\n";
	return (false);
}

bool BitcoinExchange::validateDate(std::string date) const
{
	std::istringstream	iss;
	int					ymd;

	iss.clear();
	iss.str(date.substr(0, 4));
	iss >> ymd;
	if (ymd < 1900 || ymd > 3000)
		return (false);
	iss.clear();
	iss.str(date.substr(5, 2));
	iss >> ymd;
	if (ymd < 1 || ymd > 12)
		return (false);
	iss.clear();
	iss.str(date.substr(8, 2));
	iss >> ymd;
	if (ymd < 1 || ymd > 31)
		return (false);
	return (true);
}
