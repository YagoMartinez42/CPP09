/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:14 by samartin          #+#    #+#             */
/*   Updated: 2025/12/06 12:05:20 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class RPN
{
	public:
        RPN();
        RPN(RPN& orig);
        RPN&	operator=(const RPN& orig);
        ~RPN();
    private:

};
#endif
