/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:51:37 by msafa             #+#    #+#             */
/*   Updated: 2026/01/18 22:55:56 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 7;
    Zombie *horde = zombieHorde(N,"test");
    Zombie test1;
    
    test1.setName("test1");
    test1.announce();
    for(int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}