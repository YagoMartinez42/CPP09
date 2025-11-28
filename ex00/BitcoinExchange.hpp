/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:34 by samartin          #+#    #+#             */
/*   Updated: 2025/11/18 11:54:22 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parsear csv y txt en sendos map <string, double>
//hacer función para comprobar correcto formato de fecha y de línea tanto en csv como en txt
//trasladar la carga de archivos también a la clase

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <ctime>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		int		loadFiles(const char* dataSetFile, const char* evalSetFile);
		void	mapData();
		void	showData();
	private:
		BitcoinExchange(BitcoinExchange& orig);
		BitcoinExchange&	operator=(const BitcoinExchange& orig);
		bool				validateLine(const std::string line, const std::string pattern, bool smode) const;
		void				closeFiles();
		std::ifstream					_csvDataFile;
		std::ifstream					_argTxtFile;
		std::map<std::string, double>	_dataSet;
		std::map<std::string, double>	_evalSet;
};
#endif