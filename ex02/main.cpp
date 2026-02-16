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
	std::string							argStr;
	std::clock_t						timeStart;
	unsigned int						num;

	//Check args
	if (argc < 2)
	{
		std::cerr << "Error: Natural number sequence argument(s) needed." << std::endl;
		return (1);
	}
	//Turn possible multiple args into one string
	for (int i = 1; argv[i] != NULL; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!std::isspace(argv[i][j]) && !std::isdigit(argv[i][j]) && argv[i][j] != ',' && argv[i][j] != '+')
			{
			std::cerr << "Error: Use only positive numbers in the sequence." << std::endl;
			return (1);	
			}
		}
		argStr += std::string(argv[i]) + " ";
	}

	std::stringstream argnums(argStr);

	//Dump to list and vector
	while (argnums >> num)
	{
		list2Sort.push_back(num);
		vector2Sort.push_back(num);
		while (argnums.peek() == ',' || std::isspace(argnums.peek()))
			argnums.ignore();
	}
	//Display the sequence just entered
	std::cout << "Number sequence before sorting: ";
	PmergeMe<std::list<unsigned int> >::printContainer(list2Sort);
	//Get time
	timeStart = std::clock();
	//fordjohnson sort list
	list2Sort = PmergeMe<std::list<unsigned int> >::fJSort(list2Sort);
	//Display sorted list
	std::cout << "Number sequence after sorting: ";
	PmergeMe<std::list<unsigned int> >::printContainer(list2Sort);
	std::cout << std::endl;
	//Get time end and display elapsed time for list
	std::cout << "Elapsed time for sorting list: " << (std::clock() - timeStart) << " microseconds\n";
	//Get time
	timeStart = std::clock();
	//fordjohnson sort vector
	vector2Sort = PmergeMe<std::vector<unsigned int> >::fJSort(vector2Sort);
	//Sorted vector is not asked to be displayed, third and fourth lines are explicitly requested to be the times
	//Get time end and display elapsed time for vector
	std::cout << "Elapsed time for sorting vector: " << (std::clock() - timeStart) << " microseconds\n";
	std::cout << std::endl;
	return (0);
}
