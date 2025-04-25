/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:20:32 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/25 17:13:48 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <ctime>  

class PmergeMe
{
    private:

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);

        std::vector<unsigned int> mergeSortVector(std::vector<unsigned int> &input);
        std::deque<unsigned int> mergeSortDeque(std::deque<unsigned int> &input);

        ~PmergeMe();
};

#endif

