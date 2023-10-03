/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:40:15 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/03 13:43:25 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex00 map

//ex01 stack

//ex02 vector ?
//ex02 ?

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !argv[1][0])
		return std::cerr << "No input file" << std::endl, 1;
	BitcoinExchange rates = BitcoinExchange("data.csv");
	rates.money(argv[1]);
	return 0;
}