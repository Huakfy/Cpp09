/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:59:00 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 13:50:02 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	merge_insertion(std::vector<int> &container) {
	std::vector< std::vector<int> >	pairs(container.size() / 2, std::vector<int> (2));

	//1 Create Pairs
	size_t	size = container.size();
	if (size % 2 == 1)
		size -= 1;
	for (size_t i = 0; i < size; i++)
		pairs[i / 2][i % 2] = container[i];

	//2 Sort numbers in each pairs
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i][0] > pairs[i][1]) {
			int temp = pairs[i][0];
			pairs[i][0] = pairs[i][1];
			pairs[i][1] = temp;
		}
	}

	//3 Sort pairs per biggest number
	for (size_t i = 0; i < (pairs.size() - 1); i++) {
		if (pairs[i][1] > pairs[i + 1][1]) {
			pairs[i].swap(pairs[i + 1]);
			i = -1;
		}
	}

	std::cout << "Pairs:	";
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << " " << pairs[i][0] << " " << pairs[i][1];
	}
	std::cout << std::endl;

	//4 Insert small element of first pair at the start
	std::vector<int>	result;
	result.push_back(pairs[0][0]);
	for (size_t i = 0; i < pairs.size(); i++) {
		result.push_back(pairs[i][1]);
	}
	//erase first element of pairs
	pairs.erase(pairs.begin());

	//5 Insert the remaining elements

	std::cout << "Pairs:	";
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << " " << pairs[i][0];
	}
	std::cout << std::endl;
	std::cout << "Result:	";
	for (size_t i = 0; i < result.size(); i++) {
		std::cout << " " << result[i];
	}
	std::cout << std::endl;
}