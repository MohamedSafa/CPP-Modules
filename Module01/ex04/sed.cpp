/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:00:04 by msafa             #+#    #+#             */
/*   Updated: 2026/01/23 20:53:23 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string readFile(std::ifstream& file)
{
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string replaceAll(const std::string& content,const std::string & s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t found;
    
    while((found = content.find(s1,pos)) != std::string::npos)
    {
        result += content.substr(pos,found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return result;
}

bool validateArgs(int argc)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return false;
    }
    return true;
}

bool openInputFile(std::ifstream& file, const std::string& filename)
{
    file.open(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    return true;
}

bool openOutputFile(std::ofstream& file, const std::string& filename)
{
    file.open(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: cannot create output file" << std::endl;
        return false;
    }
    return true;
}