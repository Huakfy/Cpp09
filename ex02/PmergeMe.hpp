/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:05:45 by mjourno           #+#    #+#             */
/*   Updated: 2023/10/06 20:52:48 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

# include <deque>
# include <vector>
# include <climits>
# include <cstdlib>
# include <iostream>

void	merge_insertion(std::vector<int> &container);
void	merge_insertion(std::deque<int> &container);

#endif