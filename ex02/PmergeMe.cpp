/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:20:35 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/19 22:38:14 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

std::vector<unsigned int> PmergeMe::mergeSortVector(std::vector<unsigned int> &input) {
    unsigned int len = input.size();

    if (len < 3) {
        if (len == 2 && input[0] > input[1])
            std::swap(input[0], input[1]);
        return input;
    }

    std::vector<std::pair<unsigned int, unsigned int> > groupedPairs;
    std::vector<unsigned int> extraElements;

    for (unsigned int i = 0; i + 1 < len; i += 2) {
        groupedPairs.push_back(std::make_pair(input[i], input[i + 1]));
    }

    if (len % 2 == 1)
        extraElements.push_back(input.back());

    for (size_t i = 0; i < groupedPairs.size(); ++i) {
        if (groupedPairs[i].first > groupedPairs[i].second)
            std::swap(groupedPairs[i].first, groupedPairs[i].second);
    }

    std::vector<unsigned int> mainChain;
    mainChain.push_back(groupedPairs[0].first);
    for (size_t i = 0; i < groupedPairs.size(); ++i) {
        mainChain.push_back(groupedPairs[i].second);
    }

    mainChain = mergeSortVector(mainChain);

    for (size_t i = 1; i < groupedPairs.size(); ++i) {
        extraElements.push_back(groupedPairs[i].first);
    }

    for (size_t i = 0; i < extraElements.size(); ++i) {
        std::vector<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), extraElements[i]);
        mainChain.insert(pos, extraElements[i]);
    }

    return mainChain;
}

std::deque<unsigned int> PmergeMe::mergeSortDeque(std::deque<unsigned int> &input) {
    unsigned int len = input.size();

    if (len < 3) {
        if (len == 2 && input[0] > input[1])
            std::swap(input[0], input[1]);
        return input;
    }

    std::deque<std::pair<unsigned int, unsigned int> > groupedPairs;
    std::deque<unsigned int> extraElements;

    for (unsigned int i = 0; i + 1 < len; i += 2) {
        groupedPairs.push_back(std::make_pair(input[i], input[i + 1]));
    }

    if (len % 2 == 1)
        extraElements.push_back(input.back());

    for (size_t i = 0; i < groupedPairs.size(); ++i) {
        if (groupedPairs[i].first > groupedPairs[i].second)
            std::swap(groupedPairs[i].first, groupedPairs[i].second);
    }

    std::deque<unsigned int> mainChain;
    mainChain.push_back(groupedPairs[0].first);
    for (size_t i = 0; i < groupedPairs.size(); ++i) {
        mainChain.push_back(groupedPairs[i].second);
    }

    mainChain = mergeSortDeque(mainChain);

    for (size_t i = 1; i < groupedPairs.size(); ++i) {
        extraElements.push_back(groupedPairs[i].first);
    }

    for (size_t i = 0; i < extraElements.size(); ++i) {
        std::deque<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), extraElements[i]);
        mainChain.insert(pos, extraElements[i]);
    }

    return mainChain;
}

