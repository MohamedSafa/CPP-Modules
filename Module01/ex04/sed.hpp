/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:59:59 by msafa             #+#    #+#             */
/*   Updated: 2026/01/23 20:53:52 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream> // for std::ifstream && std::oftream (input output)
#include <iostream>
#include <string>
#include <sstream>

std::string readFile(std::ifstream& file);
std::string replaceAll(const std::string& content,const std::string& s1, const std::string& s2);
bool validateArgs(int argc);
bool openInputFile(std::ifstream& file,const std::string& filename);
bool openOutputFile(std::ofstream& file,const std::string& filename);

#endif