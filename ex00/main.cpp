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

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cout << "Error: Single file argument needed.";
		return 1;
	}
		//Abrir archivo si se deja
	std::cout << std::endl;
	std::cout << TSTH << "===========================" << TSTR;
	std::cout << TSTH << "|    Test from subject    |" << TSTR;
	std::cout << TSTH << "===========================" << TSTR;
	{
		//parsear csv y txt en sendos map <string, double>
		//hacer función para comprobar correcto formato de fecha y de línea tanto en csv como en txt
	}
	return (0);
}
