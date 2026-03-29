#include "ScalarConverter.h"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter *to_copy){ *this = to_copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &original)
{
    (void)original;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convertChar(const std::string &_str)
{
    if (std::isprint(_str[0]))
        std::cout << "char: '"<< _str[0] << "'" << std::endl;
   else
        std::cout << "char: "<< "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(_str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(_str[0]) << ".0f"<< std::endl;
    std::cout << "double: " << static_cast<double>(_str[0])<< ".0"<< std::endl;
}

void ScalarConverter::convertNum(const std::string &_str, long double num)
{
    (void)_str;
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
        std::cout << "char: imposible" << std::endl;
    else 
    {
        if (std::isprint(static_cast<char>(num)))
            std::cout << "char: '"<< static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: "<< "Non displayable" << std::endl;
    }
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
       std::cout << "int: imposible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;

    if (static_cast<float>(num) == floor(num))
        std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
    }

    if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
        std::cout << "double: imposible" << std::endl;
    else
    {
        if (static_cast<float>(num) == floor(num))
            std::cout << "double: " << static_cast<double>(num) << ".0"<< std::endl;
        else
            std::cout << "double: "  << static_cast<double>(num)  << std::endl;
    }
        
}

void ScalarConverter::convertSpecial(const std::string &_str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;


    if (_str == ("nan") || _str == ("nanf"))
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } 
    else if (_str == ("inff") || _str == ("inf"))
    {
        std::cout << "float: " << "inff" << std::endl;
        std::cout << "double: "<< "inf" << std::endl;
    }
    else
    {
        std::cout << "float: " << _str[0] << "inff" << std::endl;
        std::cout << "double: " << _str[0] << "inf" << std::endl;
    }
}


static bool isChar(const std::string &_str)
{
    return (_str.length() == 1 && std::isprint(_str[0]) && !std::isdigit(_str[0]));
}
static bool isInt(const std::string &_str)
{
    size_t i = 0;
    if (_str[0] == '-' || _str[0] == '+')
        i = 1;

    if ( i == _str.length())
        return false;
    for (; i < _str.length(); i++)
    {
        if (!std::isdigit(_str[i]))
        return false;
    }
    return true ;
}
static bool isFloat(const std::string &_str)
{
    size_t i = 0;
    bool hasDot = false;

    if (_str[0] == '-' || _str[0] == '+')
        i = 1;
    size_t start = i;
    for  (; i < _str.length(); i++)
    {
        if (_str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (_str[i] == 'f')
        {   
            return (i == _str.length() -1 && start < i);
        }
        else if (!std::isdigit(_str[i]))
            return false;
    }
    return true;
    
}
static bool isDouble(const std::string &_str)
{
     size_t i = 0;
    bool hasDot = false;

    if (_str[0] == '-' || _str[0] == '+')
        i = 1;
    
    for  (; i < _str.length(); i++)
    {
        if (_str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(_str[i]))
            return false;
    }
    return true;
}

static bool isSpecial(const std::string &_str)
{
    if (_str == "-inff" || _str == "+inff" ||
        _str == "inf" || _str == "inff" ||
      _str == "nanf" || _str == "-inf" ||
      _str == "+inf" || _str == "nan")
    return true;
  return false;
}

void ScalarConverter::convert(const std::string &_toCast)
{
    if (isChar(_toCast))
        convertChar(_toCast);
    else if (isInt(_toCast))
        convertNum(_toCast, std::strtold(_toCast.c_str(), NULL));
    else if (isFloat(_toCast))
        convertNum(_toCast, std::strtold(_toCast.c_str(), NULL));
    else if (isDouble(_toCast))
        convertNum(_toCast, std::strtold(_toCast.c_str(), NULL));
    else if (isSpecial(_toCast))
        convertSpecial(_toCast);
    else 
        std::cout << "ERROR: UNKNOWN TYPE" << std::endl;

}
