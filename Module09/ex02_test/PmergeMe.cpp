/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:13 by msafa             #+#    #+#             */
/*   Updated: 2026/03/06 23:15:46 by msafa            ###   ########.fr       */
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
    for(size_t i = 0; i < _arr.size(); i++)
        std::cout << " " << _arr[i];
    std::cout << std::endl;
}

void PmergeMe::display_sorted(std::string const& label) const
{
    std::cout << label;
    if(_mainChain.empty())
    {
        for(size_t i = 0; i < _arr.size(); i++)
            std::cout << " " << _arr[i];
    }
    else
    {
        for(size_t i = 0; i < _mainChain.size(); i++)
            std::cout << " " << _mainChain[i];
    }
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
    std::cout << "Pairs extracted:" << std::endl;
    for(size_t i = 0; i < _pairs.size(); i++)
        std::cout << _pairs[i].first << " " << _pairs[i].second << std::endl;
    if(_hasStraggler)
        std::cout << "straggler: " << _straggler << std::endl;
}

void PmergeMe::mergePairs(std::vector<std::pair<int,int> >& vector)
{
    if(vector.size() <= 1)
        return;
    size_t mid = vector.size() / 2;
    std::vector<std::pair<int, int> > left(vector.begin(), vector.begin() + mid);
    std::vector<std::pair<int, int> > right(vector.begin() + mid, vector.end());
    mergePairs(left);
    mergePairs(right);
    size_t i = 0, j = 0, k = 0;
    while(i < left.size() && j < right.size())
    {
        _compCount++;
        if(left[i].first <= right[j].first)
            vector[k++] = left[i++];
        else
            vector[k++] = right[j++];
    }
    while(i < left.size())
        vector[k++] = left[i++];
    while(j < right.size())
        vector[k++] = right[j++];
}

std::vector<int> PmergeMe::fordJohnsonLoop(std::vector<int> data)
{
    if(data.empty()) return std::vector<int>();
    if(data.size() == 1) return data;
    if(data.size() == 2)
    {
        _compCount++;
        if(data[0] > data[1]) std::swap(data[0], data[1]);
        return data;
    }
    std::vector<int> main_v, pend_v;
    bool isodd = (data.size() % 2 == 1);
    for(size_t i = 0; i + 1 < data.size(); i += 2)
    {
        _compCount++;
        if(data[i] > data[i + 1])
        {
            main_v.push_back(data[i]);
            pend_v.push_back(data[i + 1]);
        }
        else
        {
            main_v.push_back(data[i + 1]);
            pend_v.push_back(data[i]);
        }
    }
    if(isodd)
        pend_v.push_back(data.back());
    std::vector<int> new_main = fordJohnsonLoop(main_v);
    std::vector<int> new_pend(new_main.size());
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
    insertSortHelper(new_main, new_pend, isodd);
    return new_main;
}

void PmergeMe::insertSortHelper(std::vector<int>& chain, std::vector<int>& pend, bool hasStraggler)
{
    if(pend.empty()) return;
    std::vector<int> winners(chain.begin(), chain.end());
    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while(jacob.back() < pend.size())
    {
        size_t i = jacob.size();
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
    }
    std::vector<size_t> order;
    order.push_back(0);
    for(size_t j = 1; j < jacob.size(); j++)
    {
        size_t end = std::min(jacob[j], pend.size());
        size_t start = jacob[j - 1] + 1;
        if(end == start && end >= pend.size())
        {
            order.push_back(end - 1);
            break;
        }
        else
        {
            for(size_t i = end; i >= start; i--)
                order.push_back(i - 1);
            if(end >= pend.size())
                break;
        }
    }
    for(size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        if(hasStraggler && idx == pend.size() - 1)
        {
            std::vector<int>::iterator lo = chain.begin();
            std::vector<int>::iterator hi = chain.end();
            while(lo < hi)
            {
                _compCount++;
                std::vector<int>::iterator mid = lo + (hi - lo) / 2;
                if(*mid < pend[idx]) lo = mid + 1;
                else hi = mid;
            }
            chain.insert(lo, pend[idx]);
        }
        else
        {
            std::vector<int>::iterator bound = std::find(chain.begin(), chain.end(), winners[idx]);
            std::vector<int>::iterator lo = chain.begin();
            std::vector<int>::iterator hi = bound;
            while(lo < hi)
            {
                _compCount++;
                std::vector<int>::iterator mid = lo + (hi - lo) / 2;
                if(*mid < pend[idx]) lo = mid + 1;
                else hi = mid;
            }
            chain.insert(lo, pend[idx]);
        }
    }
}

void PmergeMe::buildMainChain()
{
    _mainChain.push_back(_pairs[0].second);
    for(size_t i = 0; i < _pairs.size(); i++)
        _mainChain.push_back(_pairs[i].first);
    std::cout << "main chain:" << std::endl;
    for(size_t i = 0; i < _mainChain.size(); i++)
        std::cout << _mainChain[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::identifyPend()
{
    for(size_t i = 1; i < _pairs.size(); i++)
        _pend.push_back(_pairs[i].second);
    if(_hasStraggler)
        _pend.push_back(_straggler);
    std::cout << "Pend:" << std::endl;
    for(size_t i = 0; i < _pend.size(); i++)
        std::cout << _pend[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::generateJacobSthal()
{
    _jacobsthal.push_back(1);
    _jacobsthal.push_back(3);
    while(_jacobsthal.back() < _pend.size())
    {
        size_t i = _jacobsthal.size();
       _jacobsthal.push_back(_jacobsthal[i - 1] + 2 * _jacobsthal[i - 2]);
    }
    std::cout << "Jacobsthal:" << std::endl;
    for(size_t i = 0; i < _jacobsthal.size(); i++)
        std::cout << _jacobsthal[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::defineGroups()
{
    if(_pend.empty())
        return;
    for(size_t j = 0; j < _jacobsthal.size(); j++)
    {
        if(j == 0)
            _insertionOrder.push_back(0);
        else
        {
            size_t end = std::min(_jacobsthal[j],_pend.size());
            size_t start =  _jacobsthal[j - 1] + 1;
            if(end == start && end >= _pend.size())
            {
                _insertionOrder.push_back(end - 1);
                break;
            }
            else
            {
                for(size_t i = end; i >= start; i--)
                    _insertionOrder.push_back(i - 1);
                if(end >= _pend.size())
                    break;
            }   
        }
    }
    std::cout << "Insertion Order:" << std::endl;
    for(size_t i = 0; i < _insertionOrder.size(); i++)
        std::cout << _insertionOrder[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::insertPend()
{
    for(size_t i = 0; i < _insertionOrder.size();i++)
    {
        size_t idx = _insertionOrder[i];
        if(_hasStraggler && idx == _pend.size() - 1)
        {
            std::vector<int>::iterator lo = _mainChain.begin();
            std::vector<int>::iterator hi = _mainChain.end();
            while(lo < hi)
            {
                _compCount++;
                std::vector<int>::iterator mid = lo + (hi - lo) / 2;
                if(*mid < _pend[idx])
                    lo = mid + 1;
                else
                    hi = mid;
            }
            _mainChain.insert(lo, _pend[idx]);
            continue;
        }
        int pairedWinner = _pairs[idx + 1].first;
        std::vector<int>::iterator bound = std::find(_mainChain.begin(), _mainChain.end(), pairedWinner);
        std::vector<int>::iterator lo = _mainChain.begin();
        std::vector<int>::iterator hi = bound;
        while(lo < hi)
        {
            _compCount++;
            std::vector<int>::iterator mid = lo + (hi - lo) / 2;
            if(*mid < _pend[idx])
                lo = mid + 1;
            else
                hi = mid;
        }
        _mainChain.insert(lo, _pend[idx]);
    }
}

void PmergeMe::sort()
{
    if(_arr.size() == 1)
        return;
    buildPairs();
    std::vector<int> winners;
    for(size_t i = 0; i < _pairs.size(); i++)
        winners.push_back(_pairs[i].first);
    winners = fordJohnsonLoop(winners);
    std::vector<std::pair<int,int> > sorted_pairs;
    for(size_t i = 0; i < winners.size(); i++)
    {
        for(size_t j = 0; j < _pairs.size(); j++)
        {
            if(_pairs[j].first == winners[i])
            {
                sorted_pairs.push_back(_pairs[j]);
                break;
            }
        }
    }
    _pairs = sorted_pairs;
    std::cout << "Pairs after ford johnson:" << std::endl;
    for(size_t i = 0; i < _pairs.size(); i++)
        std::cout << _pairs[i].first << " " << _pairs[i].second << std::endl;
    buildMainChain();
    identifyPend();
    generateJacobSthal();
    defineGroups();
    insertPend();
    std::cout << "Total comparisons: " << _compCount << std::endl;
}