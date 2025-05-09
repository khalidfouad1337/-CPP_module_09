/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:30:18 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/29 21:03:12 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (line.find(" | ") == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, line.find(" | "));
        valueStr = line.substr(line.find(" | ") + 3);

        double value = atof(valueStr.c_str());
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        } else if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = btc.getRate(date);
        std::cout << date << " => " << valueStr << " = " 
                  << std::fixed << std::setprecision(2) << (value * rate) << std::endl;
    }

    return 0;
}
