/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:20:32 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/19 22:38:55 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>   // for std::swap
#include <iomanip>   // for std::setprecision
#include <ctime>     // for clock time

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

#endif // PMERGEME_HPP

