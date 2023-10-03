/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:40:58 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/03 15:58:34 by mjourno          ###   ########.fr       */
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

	std::string	line;
	if (std::getline(myfile, line) && line != "date,exchange_rate") {
		std::cerr << "Wrong first line of csv file" << std::endl;
		return;
	}

	while (myfile && std::getline(myfile, line)) {
		struct tm	tm = {};
		if (!strptime(line.c_str(), "%Y-%m-%d", &tm)) {
			std::cerr << "Error while parsing time on line: " << line << std::endl;
			continue;
		}
		tm.tm_isdst = -1;
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

void	BitcoinExchange::money(char *filename) {
	if (_rates.empty()) {
		std::cerr << "Error empty bitcoin rates history" << std::endl;
		return;
	}

	std::ifstream	myfile(filename);
	if (!myfile.is_open()) {
		std::cerr << "Error opening argument file" << std::endl;
		return;
	}

	std::string	line;
	if (std::getline(myfile, line) && line != "date | value") {
		std::cerr << "Wrong first line of argument file" << std::endl;
		return;
	}

	while (myfile && std::getline(myfile, line)) {
		struct tm	tm = {};
		char		*pEnd;
		pEnd = strptime(line.c_str(), "%Y-%m-%d", &tm);
		if (!pEnd) {
			std::cerr << "Error while parsing time on line: " << line << std::endl;
			continue;
		}
		tm.tm_isdst = -1;
		time_t	t = mktime(&tm);
		if (t == -1) {
			std::cerr << "Error while parsing time on line: " << line << std::endl;
			continue;
		}
		std::string	a = pEnd;
		if (a.substr(0, 3) != " | ") {
			std::cerr << "Format error on line: " << line << std::endl;
			continue;
		}
		float	f = strtof(line.c_str() + 13, &pEnd);
		if (f == HUGE_VALF || f == -HUGE_VALF || *pEnd != '\0' || f < 0 || f > 1000) {
			std::cerr << "Error while parsing line: " << line << std::endl;
			continue;
		}
		std::map<time_t,float>::iterator	it = _rates.lower_bound(t);
		if (it->first != t) {
			if (it != _rates.begin())
				it--;
			else {
				std::cerr << "No lower bound history on line: " << line << std::endl;
				continue;
			}
		}
		std::cout << line.substr(0, 11) << " => " << f << " = " << it->second * f << std::endl;
	}
}