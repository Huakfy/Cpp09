/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:40:56 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/03 15:51:55 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

#include <time.h>
# include <map>
# include <cmath>
# include <string>
# include <fstream>
# include <iostream>

class	BitcoinExchange {
	private:
		std::map<time_t, float>	_rates;
	public:
		//canon
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange	&operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange(std::string	csv);
		void	money(char *filename);
};

#endif