/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:13 by msafa             #+#    #+#             */
/*   Updated: 2026/03/15 01:00:34 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe()
    : _compCount(0)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& src)
    : _arr(src._arr),
      _compCount(src._compCount)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
    {
        this->_arr = rhs._arr;
        this->_compCount = rhs._compCount;
    }
    return *this;
}

const char* PmergeMe::InvalidInput::what() const throw()
{
    return "Invalid input";
}

void PmergeMe::parse_and_validate(int argc, char *argv[])
{
    if(argc == 1)
        throw PmergeMe::InvalidInput();
    for(int i = 1; i < argc ;i++)
    {
        if(argv[i][0] == '\0')
            throw PmergeMe::InvalidInput();
        char *endptr;
        long nb = strtol(argv[i],&endptr,10);
        if(*endptr != '\0')
            throw PmergeMe::InvalidInput();
        if(nb <= 0)
            throw PmergeMe::InvalidInput();
        if(nb > INT_MAX)
            throw PmergeMe::InvalidInput();
        this->_arr.push_back(static_cast<int>(nb));
    }
}

void PmergeMe::display_arr(std::string const& label) const
{
    std::cout << label;
    for(size_t i = 0; i < this->_arr.size(); i++)
        std::cout << " " << this->_arr[i];
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobSthal(std::vector<int> pend)
{
    std::vector<size_t> jacobSequence;
    jacobSequence.push_back(1);
    jacobSequence.push_back(3);
    while(jacobSequence.back() < pend.size())
    {
        size_t i = jacobSequence.size();
        jacobSequence.push_back(jacobSequence[i - 1] + 2 * jacobSequence[i - 2]);
    }
    return jacobSequence;
}

std::vector<size_t> PmergeMe::defineGroups(std::vector<int> pend, std::vector<size_t>& jacob)
{
    std::vector<size_t> order;

    // jacob[0]=1 is skipped: pend[0] is always inserted for free before this loop
    for(size_t j = 1; j < jacob.size(); j++)
    {
        size_t group_start = jacob[j - 1] + 1;
        size_t group_end   = std::min(jacob[j], pend.size());

        for(size_t x = group_end; x >= group_start; x--)
            order.push_back(x);

        if(group_end >= pend.size())
            break;
    }
    return order;
}

void PmergeMe::insertPend(std::vector<int>& main, std::vector<int>& pend,
                          std::vector<int>& main_v,
                          std::vector<size_t>& insertionOrder, bool hasStraggler)
{
    main.insert(main.begin(), pend[0]);

    int high = 3;
    for(size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t pos = insertionOrder[i];
        size_t idx = pos - 1;
        int    val = pend[idx];

        if(i > 0 && pos > insertionOrder[i - 1])
            high = 2 * high + 1;

        std::vector<int>::iterator winnerHi;
        bool isStraggler = (hasStraggler && idx == pend.size() - 1);
        if(isStraggler)
            winnerHi = main.end();
        else
        {
            int pairedWinner = main_v[idx];
            winnerHi = std::find(main.begin(), main.end(), pairedWinner);
            if(winnerHi != main.end()) 
                ++winnerHi;
        }

        std::vector<int>::iterator groupHi;
        if(static_cast<size_t>(high) < main.size())
            groupHi = main.begin() + high;
        else
            groupHi = main.end();

        //choose the smallest high to reduce the comparisons
        std::vector<int>::iterator hi;
        if(winnerHi < groupHi)
            hi = winnerHi;
        else
            hi = groupHi;

        std::vector<int>::iterator lo = main.begin();
        while(lo < hi)
        {
            _compCount++;
            std::vector<int>::iterator mid = lo + (hi - lo) / 2;
            if(*mid < val) 
                lo = mid + 1;
            else 
                hi = mid;
        }
        main.insert(lo, val);
    }
}

std::vector<int> PmergeMe::fordJohnsonLoop(std::vector<int>& arr)
{
    std::vector<int> main_v;
    std::vector<int> pend_v;
    std::vector<int> new_main;
    std::vector<int> new_pend;

    if(arr.size() == 1)
        return arr;
    if(arr.size() == 2)
    {
        std::vector<int> result = arr;
        _compCount++;
        if(result[0] > result[1])
            std::swap(result[0], result[1]);
        return result;
    }
    bool isodd = (arr.size() % 2 == 1);
    std::vector<int>::iterator it = arr.begin();
    while(it != arr.end())
    {
        if((it + 1) == arr.end())
            break;
        _compCount++;
        if(*it > *(it + 1))
        {
            main_v.push_back(*it);
            pend_v.push_back(*(it + 1));
        }
        else
        {
            main_v.push_back(*(it + 1));
            pend_v.push_back(*(it));
        }
        it += 2;
    }
    if(isodd)
        pend_v.push_back(arr.back());
    new_main = fordJohnsonLoop(main_v);
    new_pend.resize(new_main.size());
    std::vector<bool> used(main_v.size(), false);
    for(size_t i = 0; i < new_main.size(); i++)
    {
        for(size_t j = 0; j < main_v.size(); j++)
        {
            if(!used[j] && main_v[j] == new_main[i])
            {
                new_pend[i] = pend_v[j];
                used[j] = true;
                break;
            }
        }
    }
    if(isodd)
        new_pend.push_back(pend_v.back());
    std::vector<size_t> jacob = generateJacobSthal(new_pend);
    std::vector<size_t> insertionOrder = defineGroups(new_pend, jacob);
    std::vector<int> sorted_winners_snapshot = new_main;

    insertPend(new_main, new_pend, sorted_winners_snapshot, insertionOrder, isodd);
    return new_main;
}

void PmergeMe::sort()
{
    if(_arr.size() <= 1)
        return;
    _arr = fordJohnsonLoop(_arr);
    std::cout << "Comparisons: " << _compCount << std::endl;
}


//131 87 56 167 391 142 23 22 537 705 242 305 552 456 303 162 235 13 511 792 518
   // 65 comparisons
//1613 1430 1790 4814 8214 7541 298 1126 451 5842 2693 5236 4587 4048 4116 3904 1199 3766 6225 7269 8709
 // 64 comparisons