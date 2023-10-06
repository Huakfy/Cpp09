/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:19:36 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 12:48:08 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print(std::vector<int> container) {
	std::vector<int>::iterator	b = container.begin();
	std::vector<int>::iterator	e = container.end();
	std::cout << "	";
	while (b != e) {
		std::cout << " " << *b;
		b++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv) {
	std::vector<int>	v;

	if (argc <= 2)
		return std::cout << "Error: Must have multiple arguments" << std::endl, 1;
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return std::cout << "Error: Char other than digit found: " << argv[i][j] << std::endl, 1;
			if (j > 9)
				return std::cout << "Error: Argument bigger than int: " << argv[i] << std::endl, 1;
		}
		long	nb = strtol(argv[i], NULL, 10);
		if (nb < 0 || nb > INT_MAX)
			return std::cout << "Error: Argument bigger than int: " << argv[i] << std::endl, 1;
		v.push_back(nb);
	}

	std::cout << "Before:";
	print(v);

	merge_insertion(v);

	std::cout << "After:";
	print(v);

	return 0;
}
