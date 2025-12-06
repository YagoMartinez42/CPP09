/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:28 by samartin          #+#    #+#             */
/*   Updated: 2025/12/06 12:05:19 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN& orig) { (void)orig; }
RPN::~RPN() {}
RPN&	RPN::operator=(const RPN& orig) { (void)orig; return (*this); }