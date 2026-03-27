#pragma once

#include <cstdlib>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
class ScalarConverter
{
    private:
    
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter *to_copy);
        ScalarConverter &operator=(const ScalarConverter &original);
        ~ScalarConverter();

        static void convert(const std::string &_toCast);

        static void convertChar(const std::string &_str);
        static void convertNum(const  std::string &_str, long double num);
        static void convertSpecial(const std::string &_str);
};