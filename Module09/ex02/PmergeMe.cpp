/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:13 by msafa             #+#    #+#             */
/*   Updated: 2026/03/12 00:58:43 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib> // for strtol
#include <climits> // INT_MAX
#include <iostream>
#include <algorithm> // for std::lower_bound

PmergeMe::PmergeMe()
    :_straggler(0),_hasStraggler(false),_compCount(0)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& src)
    : _arr(src._arr),
      _pairs(src._pairs),
      _straggler(src._straggler),
      _hasStraggler(src._hasStraggler)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
    {
        this->_arr = rhs._arr;
        this->_pairs = rhs._pairs;
        this->_straggler = rhs._straggler;
        this->_hasStraggler = rhs._hasStraggler;
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

void PmergeMe::buildPairs()
{
    for(size_t i = 0; i < this->_arr.size() - 1; i += 2)
    {
        int winner = _arr[i];
        int looser = _arr[i + 1];
        _compCount++;
        if(winner > looser)
            _pairs.push_back(std::make_pair(winner,looser));
        else
            _pairs.push_back(std::make_pair(looser,winner));
    }
    if(_arr.size() % 2 != 0)
    {
        _straggler = _arr.back();
        _hasStraggler = true;
    }
}

// void PmergeMe::mergePairs(std::vector<std::pair<int,int> >& vector)
// {
//     if(vector.size() <= 1)
//         return;
//     size_t mid = vector.size() / 2;
//     std::vector<std::pair<int, int> > left(vector.begin(), vector.begin() + mid);
//     std::vector<std::pair<int, int> > right(vector.begin() + mid, vector.end());
//     mergePairs(left);
//     mergePairs(right);
//     size_t i = 0, j = 0, k = 0;
//     while(i < left.size() && j < right.size())
//     {
//         if(left[i].first <= right[j].first)
//             vector[k++] = left[i++];
//         else
//             vector[k++] = right[j++];
//     }
//     while(i < left.size())
//         vector[k++] = left[i++];
//     while(j < right.size())
//         vector[k++] = right[j++];
// }


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

// Build insertion order exactly like CEO's edit():
// jacob contains 1-indexed pend positions (e.g. [3,5,11,21]).
// For each jacob number, count down from it until hitting an already-used position.
// Any remaining positions (beyond last jacob group) are appended descending.
// Returns 1-indexed pend positions in insertion order (same format as CEO's jacob after edit).
std::vector<size_t> PmergeMe::defineGroups(std::vector<int> pend, std::vector<size_t>& jacob)
{
    std::vector<size_t> order;
    std::vector<bool>   used(pend.size() + 1, false); // 1-indexed

    if(pend.empty())
        return order;

    for(size_t j = 0; j < jacob.size(); j++)
    {
        size_t x = jacob[j];
        while(x > 1)
        {
            if(!used[x] && x <= pend.size())
            {
                order.push_back(x);   // 1-indexed position
                used[x] = true;
            }
            else
                break;
            x--;
        }
    }
    // remaining positions not covered by jacob groups, descending
    for(size_t x = pend.size(); x > 1; x--)
    {
        if(!used[x])
            order.push_back(x);
    }
    return order;
}

void PmergeMe::insertPend(std::vector<int>& main, std::vector<int>& pend,
                          std::vector<int>& main_v,
                          std::vector<size_t>& insertionOrder, bool hasStraggler)
{
    // b1 = pend[0] is guaranteed <= a1 (smallest winner), insert free at front
    main.insert(main.begin(), pend[0]);

    // insertionOrder contains 1-indexed pend positions (skips position 1 = b1)
    // main_v[pos-1] is the paired winner for pend[pos-1]
    // straggler is pend.back() and has no paired winner
    // high grows per jacobsthal group exactly as CEO's replace() does:
    //   high=3 for first group, then high=2*high+1 when entering a new group
    //   (new group detected when current 1-indexed pos > previous pos in order)
    int high = 3;
    for(size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t pos = insertionOrder[i];   // 1-indexed
        size_t idx = pos - 1;             // 0-indexed into pend and main_v
        int    val = pend[idx];

        // update high when entering a new jacobsthal group (pos jumped up)
        if(i > 0 && pos > insertionOrder[i - 1])
            high = 2 * high + 1;

        // winner-bound: pend[idx] <= its paired winner main_v[idx]
        std::vector<int>::iterator winnerHi;
        bool isStraggler = (hasStraggler && idx == pend.size() - 1);
        if(isStraggler)
            winnerHi = main.end();
        else
        {
            int pairedWinner = main_v[idx];
            winnerHi = std::find(main.begin(), main.end(), pairedWinner);
            if(winnerHi != main.end()) ++winnerHi;
        }

        // jacobsthal group bound: search at most `high` elements from start
        std::vector<int>::iterator groupHi = (static_cast<size_t>(high) < main.size())
            ? main.begin() + high
            : main.end();

        // use the tighter of the two bounds
        std::vector<int>::iterator hi = (winnerHi < groupHi) ? winnerHi : groupHi;

        std::vector<int>::iterator lo = main.begin();
        while(lo < hi) { _compCount++; std::vector<int>::iterator mid = lo + (hi - lo) / 2; if(*mid < val) lo = mid + 1; else hi = mid; }
        main.insert(lo, val);
    }
}

void PmergeMe::buildWinners()
{
    for(size_t i = 0; i < _pairs.size() ; i++)
        _winners.push_back(_pairs[i].first);
}

std::vector<int> PmergeMe::fordJohnsonLoop(std::vector<int>& arr)
{
    std::vector<int> main_v;
    std::vector<int> pend_v;
    std::vector<int> new_main;
    std::vector<int> new_pend;
    
    if(arr.empty())
        return std::vector<int>();
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
    new_pend.clear();
    new_pend.resize(new_main.size());
    for(size_t i = 0; i < new_main.size(); i++)
    {
        for(size_t j = 0; j < main_v.size(); j++)
        {
            if(main_v[j] == new_main[i])
            {
                new_pend[i] = pend_v[j];
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

std::vector<std::pair<int,int> > PmergeMe::mergePairs(std::vector<int> arr)
{
    std::vector<std::pair<int,int> > sortedPairs;
    
    for(size_t i = 0; i < arr.size(); i++)
    {
        for(size_t j = 0; j < _pairs.size(); j++)
        {
            if(_pairs[j].first == arr[i])
            {
                sortedPairs.push_back(_pairs[j]);
                break;
            }
        }
    }
    return sortedPairs;
}

void PmergeMe::sort()
{
    if(_arr.size() <= 1)
        return;
    _arr = fordJohnsonLoop(_arr);
    std::cout << "Comparisons: " << _compCount << std::endl;
}