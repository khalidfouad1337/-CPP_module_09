/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:20:35 by khalid            #+#    #+#             */
/*   Updated: 2025/04/18 19:43:30 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> // باش نحسبو الوقت
#include <iomanip> 

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::fillContainers(char **argv) {
    for (int i = 1; argv[i]; i++) {
        std::string str = argv[i];
        
        // نحاول نحولو لـ int
        int num = std::atoi(str.c_str());
        
        // تحقق واش الرقم صالح
        if (num <= 0) {
            std::cerr << "Error: invalid number \"" << str << "\"" << std::endl;
            exit(1);
        }

        _vec.push_back(num);
        _deq.push_back(num);
    }
}


void PmergeMe::sortAndShow() {
    // Before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    // --- Sort vector ---
    clock_t startVec = clock();
    mergeInsertSortVector(_vec);
    clock_t endVec = clock();

    // --- Sort deque ---
    clock_t startDeq = clock();
    mergeInsertSortDeque(_deq);
    clock_t endDeq = clock();

    // After
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    // Time
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << timeDeq << " us" << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    size_t mid = vec.size() / 2;

    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    vec.clear();

    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            vec.push_back(left[i++]);
        else
            vec.push_back(right[j++]);
    }

    while (i < left.size())
        vec.push_back(left[i++]);

    while (j < right.size())
        vec.push_back(right[j++]);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    size_t mid = deq.size() / 2;

    std::deque<int> left(deq.begin(), deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.end());

    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);

    deq.clear();

    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            deq.push_back(left[i++]);
        else
            deq.push_back(right[j++]);
    }

    while (i < left.size())
        deq.push_back(left[i++]);

    while (j < right.size())
        deq.push_back(right[j++]);
}
