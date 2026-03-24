#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter *to_copy)
{

}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &original)
{
    if (this != &original)
    {   
        this = original;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}


static char convert(const std::string &_toCast)
{
    
}