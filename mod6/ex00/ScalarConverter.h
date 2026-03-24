#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
private:
    
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter *to_copy);
    ScalarConverter &operator=(const ScalarConverter &original);
    ~ScalarConverter();

    static char convert(const std::string &_toCast);
    // static char convertChar(std::string _value);
    // static int convertInt(std::string _value);
    // static float convertFloat(std::string _value);
    // static double convertDouble(std::string _value);
};

