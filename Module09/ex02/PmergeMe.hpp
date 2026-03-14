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

#include <vector>
#include <string>
#include <exception>

class PmergeMe
{
    private:
        std::vector<int> _arr;
        size_t _compCount;
        std::vector<int> fordJohnsonLoop(std::vector<int>& arr);
        std::vector<size_t> generateJacobSthal(std::vector<int> pend);
        std::vector<size_t> defineGroups(std::vector<int> pend, std::vector<size_t>& jacob);
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
