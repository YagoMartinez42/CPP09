/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:46:25 by samartin          #+#    #+#             */
/*   Updated: 2026/01/20 18:26:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>

template < typename T = std::vector<unsigned int> >
class PmergeMe
{
	public:
		static T& fJShort(T& collection)
		{
			unsigned int			p1;
			unsigned int			p2;
			T						high;
			T						low;
			typename T::iterator	it = collection.begin();
			typename T::iterator	nx = collection.begin();

			if (collection.size() < 2)
				return (collection);
			nx++;
			while (it != collection.end())
			{
				p1 = *it;
				if (nx != collection.end())
				{
					p2 = *nx;
					if (p1 > p2)
					{
						high.push_back(p1);
						low.push_back(p2);
					}
					else
					{
						high.push_back(p2);
						low.push_back(p1);
					}
				}
				else
					high.push_back(p1);
				it++;
				nx++;
				if (it != collection.end())
					it++;
				if (nx != collection.end())
					nx++;
			}
			if (!PmergeMe::isShorted(high))
				PmergeMe::fJShort(high);
			//Do insertion of `low` values into `high` with binary search or Jacobsthal sequence
			return (collection);
		}

		static unsigned int binarySearch(T& collection, unsigned int value)
		{
			return (0);
		}

		static bool isShorted(T& collection)
		{
			typename T::iterator	it = collection.begin();
			typename T::iterator	nx = collection.begin();

			if (collection.size() < 2)
				return (true);
			nx++;
			while (nx != collection.end())
			{
				if (*it > *nx)
					return(false);
				it++;
				nx++;
			}
			return (true);
		}
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& orig);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& orig);
};

#endif