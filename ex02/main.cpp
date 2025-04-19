/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:44:21 by khalid            #+#    #+#             */
/*   Updated: 2025/04/18 19:44:23 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [positive numbers]" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.fillContainers(argv);
    sorter.sortAndShow();

    return 0;
}
