/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:11 by msafa             #+#    #+#             */
/*   Updated: 2026/03/06 21:37:57 by msafa            ###   ########.fr       */
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
        int _straggler;
        bool _hasStraggler;
        size_t _compCount;
        void buildPairs();
        void mergePairs(std::vector<std::pair<int,int> >& vector);
        std::vector<int> fordJohnsonLoop(std::vector<int> data);
        void insertSortHelper(std::vector<int>& chain, std::vector<int>& pend, bool hasStraggler);
        void buildMainChain();
        void identifyPend();
        void generateJacobSthal();
        void defineGroups();
        void insertPend();
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        void parse_and_validate(int argc, char *argv[]);
        void display_arr(std::string const& label) const;
        void display_sorted(std::string const& label) const;
        class InvalidInput : public std::exception
        {
            public:
                const char* what() const throw();
        };
        void sort();
};

#endif
