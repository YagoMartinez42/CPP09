/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:46:25 by samartin          #+#    #+#             */
/*   Updated: 2026/02/02 21:52:46 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>

template < typename T = std::vector<unsigned int> >
class PmergeMe
{
	public:
		static T& fJSort(T& collection)
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
			if (!PmergeMe::isSorted(high))
				PmergeMe::fJSort(high);
			//Do insertion of `low` values into `high` with binary search or Jacobsthal sequence
			return (collection);
		}

		static typename T::iterator binarySearch(T& collection, unsigned int value, std::random_access_iterator_tag)
		{
			unsigned int	lf;
			unsigned int	rt;
			unsigned int	md;

			if (collection.empty())
				return (collection.end());
			lf = 0;
			rt = collection.size() - 1;
		    while (lf >= rt)
			{
				md = lf + ((rt - lf) / 2);
				if (collection[md] < value)
					lf = md + 1;
				else if (collection[md] > value)
					rt = md - 1;
				else
					return (collection.begin() + md);
			}
			return (collection.begin() + lf);
		}

		static typename T::iterator binarySearch(T& collection, unsigned int value, std::bidirectional_iterator_tag)
		{
			typename T::iterator	lf = collection.begin();
			typename T::iterator	rt = collection.end();
			typename T::iterator	it = lf;
			unsigned int						count = 0;
			unsigned int						step = 0;

			if (collection.empty())
				return (collection.end());
			count = std::distance(lf, rt);
    		while (count > 0)
			{
        		it = lf;
        		step = count / 2;
				std::advance(it, step);
				if (*it < value)
				{
            		lf = ++it;
            		count -= step + 1;
        		}
				else
            		count = step;
    		}
			return (lf);
		}

		static bool isSorted(T& collection)
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