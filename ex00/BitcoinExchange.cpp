/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:24:28 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/25 17:13:05 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            float rate = std::strtof(rateStr.c_str(), NULL);
            _exchangeRates[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }

    if (it != _exchangeRates.begin()) {
        --it;
        return it->second;
    }

    std::cerr << "Error: no exchange rate available for this date or before." << std::endl;
    return 0.0f;
}
