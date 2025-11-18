/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:54:58 by samartin          #+#    #+#             */
/*   Updated: 2025/11/13 15:18:02 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char** argv)
{
	std::string		myText;
	std::ifstream	csvData;
	std::ifstream	argTxtFile;

	if (argc != 2)
	{
		std::cout << "Error: Single file argument needed.";
		return (1);
	}
	else
	{
		try
		{
			csvData.open("data.csv");
			argTxtFile.open(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}
	}
	while (std::getline (csvData, myText))
	{

	}

	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|    Test from subject    |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		
			

	}
	return (0);
}
