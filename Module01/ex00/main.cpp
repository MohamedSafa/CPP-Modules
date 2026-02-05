/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:30:38 by msafa             #+#    #+#             */
/*   Updated: 2026/01/18 21:08:11 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie = newZombie("HeapZombie");
    
    heapZombie->announce();
    randomChump("StackZombie");
    delete heapZombie;
    return 0;
}