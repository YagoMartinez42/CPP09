/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-09 17:46:25 by samartin          #+#    #+#             */
/*   Updated: 2025-12-09 17:46:25 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>

template < typename T = std::vector<unsigned int>>
class PmergeMe
{
	public:
		static T fJShort(T& collection)
		{
			return (collection);
		}
		static size_t binarySearch(const T& collection, unsigned int value) const
		{
			return (0);
		}
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& orig);
		PmergeMe~();
		PmargeMe& operator=(const PmergeMe& orig);
};

#endif