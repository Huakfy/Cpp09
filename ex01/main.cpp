/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:02:40 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/04 13:51:38 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main (int argc, char **argv) {
	if (argc != 2)
		return std::cout << "Error: Must have one and only one argument" << std::endl, 1;
	std::string	chars = " 0123456789+-/*";
	std::string	operators = "+-/*";
	std::string	operands = "0123456789";
	int	i;
	int	nbOperator = 0;
	int	nbOperand = 0;
	for (i = 0; argv[1][i]; i++) {
		if ((i == 0 || i == 2) && !('0' <= argv[1][i] && argv[1][i] <= '9'))
			return std::cout << "Error: Wrong char near: '" << argv[1][i] << "' char N° " << i << std::endl, 1;
		if (i%2 == 1 && argv[1][i] != ' ')
			return std::cout << "Error: Wrong char near: '" << argv[1][i] << "' char N° " << i << std::endl, 1;
		if (chars.find(argv[1][i]) == std::string::npos)
			return std::cout << "Error: Wrong char near: '" << argv[1][i] << "' char N° " << i << std::endl, 1;
		if (operators.find(argv[1][i]) != std::string::npos)
			nbOperator++;
		else if (operands.find(argv[1][i]) != std::string::npos)
			nbOperand++;
	}
	if (i < 5)
		return std::cout << "Error: Not enough chars" << std::endl, 1;
	if (nbOperand < (nbOperator - 1))
		return std::cout << "Error: Not enough operators" << std::endl, 1;
	std::cout << RPN(argv[1]) << std::endl;
	return 0;
}