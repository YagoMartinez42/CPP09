/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:44:00 by samartin          #+#    #+#             */
/*   Updated: 2025/12/05 14:02:06 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "main.hpp"

int main(int argc, char** argv)
{
	std::list<unsigned int>				list2Sort;
	std::list<unsigned int>::iterator	itl;
	std::vector<unsigned int>			vector2Sort;
	std::vector<unsigned int>::iterator	itv;
	std::clock_t						timeStart;
	unsigned int						num;

	//Check args
	if (argc != 2)
	{
		std::cerr << "Error: Single sequence argument needed." << std::endl;
		return (1);
	}
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (!std::isspace(argv[1][i]) && !std::isdigit(argv[1][i]) && argv[1][i] != ',')
		{
		std::cerr << "Error: Use only positive numbers in the sequence." << std::endl;
		return (1);	
		}
	}

	std::stringstream argnums(argv[1]);

	//Dump to list and vector
	while (argnums >> num)
	{
		list2Sort.push_back(num);
		vector2Sort.push_back(num);
		while (argnums.peek() == ',' || std::isspace(argnums.peek()))
			argnums.ignore();
	}

	//Get time
	timeStart = std::clock();
		
		//fordjohnson sort list


	//Get time end
	//Display elapsed time
	std::cout << "Elapsed time for sorting list: " << (std::clock() - timeStart) / static_cast<double>(CLOCKS_PER_SEC) << "\n";

	//Get time
	timeStart = std::clock();

		//fordjohnson sort vector
	
	//Get time end
	//Display elapsed time
	std::cout << "Elapsed time for sorting vector: " << (std::clock() - timeStart) / static_cast<double>(CLOCKS_PER_SEC) << "\n";

/* //Visualization
	for (itl = list2Sort.begin(); itl != list2Sort.end(); itl++)
		std::cout << *itl << " ";
	std::cout << std::endl;
	for (itv = vector2Sort.begin(); itv != vector2Sort.end(); itv++)
		std::cout << *itv << " ";
	std::cout << std::endl; */
	return (0);
}
