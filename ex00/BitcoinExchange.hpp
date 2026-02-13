/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:34 by samartin          #+#    #+#             */
/*   Updated: 2025/12/05 14:04:09 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		int		loadFiles(const char* dataSetFile, const char* evalSetFile);
		void	mapData();
		void	execute();
		void	showData() const;
	private:
		BitcoinExchange(BitcoinExchange& orig);
		BitcoinExchange&	operator=(const BitcoinExchange& orig);
		bool				validateDataLine(const std::string line) const;
		bool				validateInputLine(const std::string line) const;
		bool				validateDate(const std::string line) const;
		void				closeFiles();
		std::ifstream					_csvDataFile;
		std::ifstream					_argTxtFile;
		std::map<std::string, double>	_dataSet;
};
#endif