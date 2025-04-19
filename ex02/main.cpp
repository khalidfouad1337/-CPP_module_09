/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:44:21 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/19 22:38:00 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " number1 number2 number3 ..." << std::endl;
        return 1;
    }

    std::vector<unsigned int> inputVec;
    std::deque<unsigned int> inputDeq;

    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num < 0)
        {
            std::cerr << "Only positive numbers are allowed!" << std::endl;
            return 1;
        }
        inputVec.push_back(static_cast<unsigned int>(num));
        inputDeq.push_back(static_cast<unsigned int>(num));
    }

    PmergeMe sorter;

    std::cout << "Before sorting (vector): ";
    for (size_t i = 0; i < inputVec.size(); ++i)
        std::cout << inputVec[i] << " ";
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    std::vector<unsigned int> sortedVec = sorter.mergeSortVector(inputVec);
    std::clock_t endVec = std::clock();

    std::cout << "After sorting (vector):  ";
    for (size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;

    double timeVec = 1000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    std::cout << "Time taken (vector): " << std::fixed << std::setprecision(5) << timeVec << " ms" << std::endl;

    std::clock_t startDeq = std::clock();
    std::deque<unsigned int> sortedDeq = sorter.mergeSortDeque(inputDeq);
    std::clock_t endDeq = std::clock();

    double timeDeq = 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
    std::cout << "Time taken (deque):  " << std::fixed << std::setprecision(5) << timeDeq << " ms" << std::endl;

    return 0;
}
