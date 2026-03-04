/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:50:28 by msafa             #+#    #+#             */
/*   Updated: 2026/02/21 01:51:45 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

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

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str(),std::ios::in);
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file,line);
    while(std::getline(file,line))
    {
       size_t pos = line.find(',');
       std::string date = line.substr(0,pos);
       std::string price = line.substr(pos + 1);
       std::stringstream ss(price,std::ios::in);
       float rate;
       ss >> rate;
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
    std::getline(file,line);
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
        if(date.size() != 10 || date[4] != '-' || date[7] != '-')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        bool validate = true;
        for(size_t i = 0; i < date.size();i++)
        {
            if(i == 4 || i == 7)
                continue;
            if(!std::isdigit(date[i]))
            {
                validate = false;
                break;
            }
        }
        if(validate == false)
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
