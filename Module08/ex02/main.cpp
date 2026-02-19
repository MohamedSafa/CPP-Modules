/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 22:54:15 by msafa             #+#    #+#             */
/*   Updated: 2026/02/19 16:55:57 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // subject test
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    // std::list test (should print same output as MutantStack)
    std::cout << "\n--- std::list test ---\n" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it2 = lst.begin();
    std::list<int>::iterator ite2 = lst.end();
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    // reverse iterators
    std::cout << "\n--- reverse iterators test ---\n" << std::endl;
    MutantStack<int> test1;
    test1.push(42);
    test1.push(43);
    test1.push(44);
    MutantStack<int>::reverse_iterator rit = test1.rbegin();
    MutantStack<int>::reverse_iterator rite = test1.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    // copy & assignment constructors 
    std::cout << "\n--- copy & assignment constructors ---\n" << std::endl;
    MutantStack<std::string> test2;
    test2.push("hello");
    test2.push("world");
    MutantStack<std::string> test3(test2);
    MutantStack<std::string>::iterator test3_it = test3.begin();
    MutantStack<std::string>::iterator test3_ite = test3.end();
    while (test3_it != test3_ite)
    {
        std::cout << *test3_it << std::endl;
        ++test3_it;
    }
    std::cout << std::endl;
    MutantStack<std::string> test4;
    test4 = test2;
    MutantStack<std::string>::const_iterator test4_it = test4.begin();
    MutantStack<std::string>::const_iterator test4_ite = test4.end();
    while (test4_it != test4_ite)
    {
        std::cout << *test4_it << std::endl;
        ++test4_it;
    }
    // test empty
    std::cout << "\n--- empty() test---\n" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Empty Stack: " << (emptyStack.empty() ? "true" : "false") << std::endl;
    emptyStack.push(42);
    std::cout << "Empty Stack: " << (emptyStack.empty() ? "true" : "false") << std::endl;
    return 0;
}