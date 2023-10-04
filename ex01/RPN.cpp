/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:57:46 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/04 13:45:54 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN(char *arg) {
	std::string	str = arg;
	std::stack<int>	stck;
	std::string	chars = " +-/*";
	for (int i = 0; str[i]; i++) {
		if (chars.find(str[i]) == std::string::npos)
			stck.push(str[i] - '0');
		else if (str[i] != ' ') {
			int b = stck.top();
			stck.pop();
			int a = stck.top();
			stck.pop();
			if (str[i] == '+')
				stck.push(a + b);
			else if (str[i] == '-')
				stck.push(a - b);
			else if (str[i] == '*')
				stck.push(a * b);
			else
				stck.push(a / b);
		}
	}
	return stck.top();
}