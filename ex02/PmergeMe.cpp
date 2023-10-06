/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:59:00 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 16:14:12 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	recursive_sort(std::vector<int> &x, std::vector<int> &y, size_t size) {
	for (size_t i = 0; i < ((size / 2) - 1); i++) {
		if (x[i] > x[i + 1]) {
			int	temp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = temp;

			int	temp2 = y[i];
			y[i] = y[i + 1];
			y[i + 1 ] = temp2;
			recursive_sort(x, y, size);
		}
	}
}

void	merge_insertion(std::vector<int> &container) {
	std::vector<int>	x;
	std::vector<int>	y;

	//1 Create Pairs
	size_t	size = container.size();
	if (container.size() % 2 == 1)
		size--;
	for (size_t i = 0; i < size; i++) {
		if (i % 2 == 0)
			x.push_back(container[i]);
		else
			y.push_back(container[i]);
	}
	if (container.size() % 2 == 1)
		y.push_back(container.back());

	//2 Sort numbers in each pairs
	for (size_t i = 0; i < size / 2; i++) {
		if (x[i] < y[i]) {
			int	temp = x[i];
			x[i] = y[i];
			y[i] = temp;
		}
	}

	//3 Sort pairs per biggest number
	recursive_sort(x, y, size);

	//4 Insert small element of first pair at the start
	x.insert(x.begin(), y[0]);
	y.erase(y.begin());

	//5 Insert the remaining elements

	std::cout << "x:	";
	for (size_t	i = 0; i < x.size(); i++) {
		std::cout << " " << x[i];
	}
	std::cout << std::endl;
	std::cout << "y:	";
	for (size_t	i = 0; i < y.size(); i++) {
		std::cout << " " << y[i];
	}
	std::cout << std::endl;
}