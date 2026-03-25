/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:50:28 by msafa             #+#    #+#             */
/*   Updated: 2026/03/22 21:45:12 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
    :_db(src._db)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if(this != &rhs)
        this->_db = rhs._db;
    return *this;
}

static bool isValidDate(const std::string& date)
{
    if(date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for(size_t i = 0; i < date.size(); i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }
    const char *s = date.c_str();
    char *end;
    int year = (int)strtol(s,&end,10);
    int month = (int)strtol(end+1, &end, 10);
    int day=(int)strtol(end+1,&end,10);

    if(month < 1 || month >12 || day < 1)
        return false;
    const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if(month == 2 && leapYear)
        return day <= 29;
    else
        return day <= daysInMonth[month - 1];
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str(),std::ios::in);
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    if(!std::getline(file, line) || line != "date,exchange_rate")
        throw std::runtime_error("Error: database is empty or invalid.");
    while(std::getline(file,line))
    {
        size_t pos = line.find(',');
        if(pos == std::string::npos)
            continue;
        std::string date = line.substr(0,pos);
        std::string price = line.substr(pos + 1);
        bool valid = true;
        valid = isValidDate(date);
        if(!valid)
            continue;
        std::stringstream ss(price);
        float rate;
        if(!(ss >> rate) || rate < 0)
            continue;
        this->_db[date] = rate;
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str(),std::ios::in);
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    std::string line;
    if(!std::getline(file, line) || line != "date | value")
        throw std::runtime_error("Error: input file is empty or invalid.");
    while(std::getline(file,line))
    {
        size_t pos = line.find(" | ");
        if(pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0,pos);
        std::string amount = line.substr(pos + 3);
        if(!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::stringstream ss(amount);
        float value;
        if(!(ss >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if(value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string,float>::iterator it = _db.lower_bound(date);
        if(it == _db.end() || it->first != date )
        {
            if(it == _db.begin())
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    file.close();
}
