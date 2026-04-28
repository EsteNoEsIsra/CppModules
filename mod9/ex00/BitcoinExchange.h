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
        std::map<std::string , double> _data_map;
        std::ifstream _file_data;
        std::string _dates;
        double _value_num ; 

    public:
        BitcoinExchange();
        BitcoinExchange(char *filename, char *datafile);
        BitcoinExchange(const BitcoinExchange &to_copy);
        BitcoinExchange& operator=(const BitcoinExchange &original);
        ~BitcoinExchange();

        void fecthDataFromFile(char *file);

    class ReadFailed : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif