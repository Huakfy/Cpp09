/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:19:36 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 20:54:32 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <bits/stdc++.h>
#include <sys/time.h>

template<typename T>
void	print(T container) {
	typename T::iterator	b = container.begin();
	typename T::iterator	e = container.end();
	std::cout << "	";
	while (b != e) {
		std::cout << " " << *b;
		b++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv) {
	std::vector<int>	v;
	std::deque<int>		d;

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
		d.push_back(nb);
	}

	std::cout << "Before:";
	print(v);

	struct timeval start, end;
	gettimeofday(&start, NULL);

	merge_insertion(v);

	gettimeofday(&end, NULL);

	merge_insertion(d);

	std::cout << "After:";
	print(v);

	double time_taken;
	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	std::cout << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;


	for (size_t i = 0; i < v.size() - 1; i++) {
		if (v[i] > v [i + 1])
			std::cout << "Error" << std::endl;
	}

	return 0;
}
