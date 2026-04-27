#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() : _dates(""), _value_num(0)
{

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy){*this = to_copy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{

}

BitcoinExchange::~BitcoinExchange()
{

}

const char *BitcoinExchange::ReadFailed::what() const throw()
{
    return "Error: Read Failed ";
}