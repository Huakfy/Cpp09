/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:59:00 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 19:28:27 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int Jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

int binarySearch(std::vector<int> &a, int item, int low, int high) {
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

static void	insertion(std::vector<int> &x, std::vector<int> &y) {
	int	erased = 0;
	for (int i = 2; y.size() > 0; i++) {
		int	j = Jacobsthal(i) - erased;

		while (j >= 0) {
			if ((long unsigned int)j < y.size()) {
				x.insert(x.begin() + binarySearch(x, y[j], 0, x.size()), y[j]);
				y.erase(y.begin() + j);
				erased++;
			}
			j--;
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
	for (size_t i = 0; i < ((size / 2) - 1); i++) {
		if (x[i] > x[i + 1]) {
			int	temp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = temp;

			int	temp2 = y[i];
			y[i] = y[i + 1];
			y[i + 1 ] = temp2;
			i = -1;
		}
	}

	//4 Insert small element of first pair at the start
	x.insert(x.begin(), y[0]);
	y.erase(y.begin());

	//5 Insert the remaining elements
	insertion(x, y);

	//print
	container = x;
}