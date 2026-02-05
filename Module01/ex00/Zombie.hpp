/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:28:48 by msafa             #+#    #+#             */
/*   Updated: 2026/01/19 21:19:10 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include  <iostream>
#include <string>

class Zombie
{
  private:
    std::string _name;
  public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce (void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif