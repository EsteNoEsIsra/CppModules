#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <ctype.h>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string , int> map_c;
        std::string _dates;
        int _value_num ; 

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &to_copy);
        BitcoinExchange& operator=(const BitcoinExchange &original);
        ~BitcoinExchange();


    class ReadFailed : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif