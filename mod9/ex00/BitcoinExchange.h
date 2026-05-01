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
        const char *_file_data;
    
        bool isValidDate(std::string date);
        bool isValidValue(std::string value);
        void printLine(std::string date ,double n);
    public:
        BitcoinExchange();
        BitcoinExchange(const char *datafile);
        BitcoinExchange(const BitcoinExchange &to_copy);
        BitcoinExchange& operator=(const BitcoinExchange &original);
        ~BitcoinExchange();

        void fecthDataFromFile(const char *file);
        void exchangeBitcoins(const char* file_in);
        const char *getFiledataName();

        std::map<std::string , double>&getMapcontainer();

    class ReadFailed : public std::exception
    {
        virtual const char* what() const throw();
    };
    class BadInput : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif