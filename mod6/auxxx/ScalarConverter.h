#pragma once

#include <cstdlib>
#include <iostream>
#include <limits>
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


        void convertChar(const std::string &_str);
        void convertNum(const  std::string &_str, long double num);
        void convertSpecial(const std::string &_str);
};

