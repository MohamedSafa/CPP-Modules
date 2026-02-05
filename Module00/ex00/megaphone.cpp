/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:10:48 by msafa             #+#    #+#             */
/*   Updated: 2026/01/17 13:47:25 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc,char **argv)
{
    
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for(int i = 1 ; i < argc; i++)
    {
        for(int j = 0 ; argv[i][j]; j++)
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
        }
    }
    return 0;
}
