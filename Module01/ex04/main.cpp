/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:25:37 by msafa             #+#    #+#             */
/*   Updated: 2026/01/23 21:10:57 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc , char*argv[])
{
    if (!validateArgs(argc))
        return 1;
    if (std::string(argv[2]).empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inputfile;
    std::ofstream outputfile;

    if (!openInputFile(inputfile, filename))
        return 1;
    if (!openOutputFile(outputfile, filename + ".replace"))
    {
        inputfile.close();
        return 1;
    }
    std::string content = readFile(inputfile);
    std::string result = replaceAll(content,s1,s2);
    outputfile << result;
    inputfile.close();
    outputfile.close();
    return 0;
}