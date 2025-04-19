/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:20:32 by khalid            #+#    #+#             */
/*   Updated: 2025/04/18 19:20:33 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe(); // constructor
    ~PmergeMe(); // destructor

    void fillContainers(char **argv); // تعمّر الأرقام
    void sortAndShow(); // ترتّب وتعرض النتائج

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    void mergeInsertSortVector(std::vector<int>& vec);
    void mergeInsertSortDeque(std::deque<int>& deq);
};

#endif
