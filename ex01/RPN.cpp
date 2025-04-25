/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:59:42 by khalid            #+#    #+#             */
/*   Updated: 2025/04/25 17:10:50 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            _stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands.");
            }

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero.");
                result = a / b;
            }

            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }

    return _stack.top();
}
