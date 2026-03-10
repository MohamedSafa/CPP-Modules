/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:11 by msafa             #+#    #+#             */
/*   Updated: 2026/03/10 01:58:51 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector> //container type
#include <string> // std::string
#include <exception> // exception class
#include <utility> // std::pair

class PmergeMe
{
    private:
        std::vector<int> _arr;
        std::vector<std::pair<int,int> > _pairs;
        std::vector<int> _mainChain;
        std::vector<int> _pend;
        std::vector<size_t> _jacobsthal;
        std::vector<size_t> _insertionOrder;
        std::vector<int> _winners;
        int _straggler;
        bool _hasStraggler;
        size_t _compCount;
        void buildPairs();
        void buildWinners();
        std::vector<int> fordJohnsonLoop(std::vector<int>& arr);
        std::vector<std::pair<int,int> > mergePairs(std::vector<int> arr);
        void buildMainChain(std::vector<int> arr);
        void identifyPend();
        std::vector<size_t> generateJacobSthal(std::vector<int> pend);
        std::vector<size_t> defineGroups(std::vector<int> pend,std::vector<size_t>& jacob);
        void insertPend(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& main_v, std::vector<size_t>& insertionOrder, bool hasStraggler);
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        void parse_and_validate(int argc, char *argv[]);
        void display_arr(std::string const& label) const;
        class InvalidInput : public std::exception
        {
            public:
                const char* what() const throw();
        };
        void sort();
};

#endif
