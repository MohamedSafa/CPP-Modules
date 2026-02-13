/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:13:01 by msafa             #+#    #+#             */
/*   Updated: 2026/02/12 22:23:18 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool check_pseudo_literals(const std::string& literal)
{
    if(literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    return false;
}

static bool check_if_char(const std::string& literal)
{
    if(literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    if(literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}

static bool check_if_int(double nb)
{
    if(nb >= INT_MIN && nb <= INT_MAX && nb == std::floor(nb))
        return true;
    return false;
}

static void print_int(double nb)
{
    std::cout << "int: " << static_cast<int>(nb) << std::endl;
}

static void print_float(double nb)
{
    if(nb == std::floor(nb))
        std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
}

static void print_double(double nb)
{
    if(nb == std::floor(nb))
        std::cout << "double: " << nb << ".0" << std::endl;
    else
        std::cout << "double: " << nb << std::endl;
}

static void print_char_type(double nb)
{
    if(nb >= 0 && nb <= 127)
    {
        if(std::isprint(static_cast<int>(nb)))
            std::cout << "char: '" << static_cast<char>(nb) << "\'" << std::endl;
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
}

static void print_pseudo(const std::string& literal)
{
    std::cout << "char: impossible\n"
              << "int: impossible\n";
    if(literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff\n"
                  << "double: +inf\n";
    }
    else if(literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff\n"
                  << "double: -inf\n";
    }
    else
    {
        std::cout << "float: nanf\n"
                  << "double: nan\n";
    }
}

static void print_char(const std::string& literal)
{
    char c;
    if(literal.length() == 1)
        c = literal[0];
    else
        c = literal[1];
    std::cout << "char: '" << c << "'" << std::endl;
    print_int(static_cast<double>(c));
    print_float(static_cast<double>(c));
    print_double(static_cast<double>(c));
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout.precision(10);
    if(literal.empty())
    {
        std::cout << "Error: empty input\n";
        return;
    }
    if(check_pseudo_literals(literal))
    {
        print_pseudo(literal);
        return;
    }
    else if(check_if_char(literal))
    {
        print_char(literal);
        return;
    }
    else
    {
        char *end;
        double nb;
        nb = strtod(literal.c_str(),&end);
        if(*end == '\0')
        {
            if(check_if_int(nb))
            {
                print_char_type(nb);
                print_int(nb);
                print_float(nb);
                print_double(nb);
            }
            else
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                print_float(nb);
                print_double(nb);
            }
        }
        else if(*end == 'f' && *(end + 1) == '\0')
        {
            if(check_if_int(nb))
            {
                print_char_type(nb);
                print_int(nb);
                print_float(nb);
                print_double(nb);
            }
            else
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                print_float(nb);
                print_double(nb);
            }
        }
        else
            std::cout << "Error: invalid input\n";
    }
}