/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:35 by kfouad            #+#    #+#             */
/*   Updated: 2025/04/15 15:23:55 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile); // constructor
    float getRate(const std::string& date) const; // يرجع الثمن فداك التاريخ أو أقرب قبلو
private:
    std::map<std::string, float> _exchangeRates;
    void loadDatabase(const std::string& dbFile);
};

#endif
