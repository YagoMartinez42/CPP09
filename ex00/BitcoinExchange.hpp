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

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		int		loadFiles(char* dataSetFile, char* evalSetFile);
		void	mapData();
		int	validateLine(std::string line);
		void	closeFiles();
	private:
		BitcoinExchange(BitcoinExchange& orig);
		BitcoinExchange&	operator=(const BitcoinExchange& orig);
		std::ifstream					_csvDataFile;
		std::ifstream					_argTxtFile;
		std::map<std::string, double>	_dataSet;
		std::map<std::string, double>	_evalSet;
};
#endif