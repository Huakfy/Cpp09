/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:40:58 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/02 17:32:10 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src) { _rates = src._rates; return *this; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string csv) {
	if (csv.size() < 4 || csv.find(".csv", csv.size() - 4) == std::string::npos) {
		std::cerr << "Wrong file format, must be csv" << std::endl;
		return;
	}

	std::ifstream	myfile(csv.c_str());
	if (!myfile.is_open()) {
		std::cerr << "Error opening csv file" << std::endl;
		return;
	}

	std::string		line;
	if (std::getline(myfile, line) && line != "date,exchange_rate") {
		std::cerr << "Wrong first line of csv file" << std::endl;
		return;
	}

	while (myfile && std::getline(myfile, line)) {
		struct tm	tm;
		if (!strptime(line.c_str(), "%Y-%m-%d", &tm)) {
			std::cerr << "Error while parsing time on line: " << line << std::endl;
			continue;
		}
		time_t	t = mktime(&tm);
		if (t == -1) {
			std::cerr << "Error while parsing time on line: " << line << std::endl;
			continue;
		}
		char	*pEnd;
		float	f = strtof(line.c_str() + 11, &pEnd);
		if (f == HUGE_VALF || f == -HUGE_VALF || *pEnd != '\0' || f < 0) {
			std::cerr << "Error while parsing line: " << line << std::endl;
			continue;
		}
		_rates.insert(std::pair<time_t, float>(t, f));
	}
}