#include "ScalarConverter.h"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter *to_copy){ *this = to_copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &original)
{
    if (this != &original)
    {   
        this = original;
    }
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
    std::cout << "float: " << static_cast<float>(_str[0]) << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(_str[0])<< std::endl;
}

void ScalarConverter::convertNum(const std::string &_str, long double num)
{
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
        std::cout << "char: overflow" << std::endl;
    else 
    {
        if (std::isprint(static_cast<char>(num)))
            std::cout << "char: '"<< static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: "<< "Non displayable" << std::endl;
    }
    if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        std::cout << "int: overflows" << std::endl;
    else
        std::cout << "int: " << std::atoi(_str.c_str()) << std::endl;

    if (number < -std::numeric_limits<float>::max() || number > std::numeric_limits<float>::max())
        std::cout << "float: overflows" << std::endl;
    else
        std::cout << "float: " << std::strtof(_str.c_str(), NULL) << "f"<< std::endl;

  if (number < -std::numeric_limits<double>::max() || number > std::numeric_limits<double>::max())
        std::cout << "double: overflows" << std::endl;
    else
        std::cout << "double: " << std::strtod(_str.c_str(), NULL) << std::endl;
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
  else
  {
    std::cout << "float: " << _str[0] << "inff" << std::endl;
    std::cout << "double: " << _str[0] << "inf" << std::endl;
  }
}


static bool ScalarConverter::isChar(const std::string &_str)
{
    if (_str[0] && std::isprint(_str[0]) && !std::isdigit(_str[0]))
        return true;
    return false;
}
static bool ScalarConverter::isInt(const std::string &_str)
{
    size_t i = 0;
    if (_str[0] == '-' || _str[0] == '+')
        i = 1;

    if ( i == _str.lenght())
        return false;
    for (; i < _str.lenght(); i++)
    {
        if (!std::isdigit(_str[i]))
        return false;
    }
    return true ;
}
static bool ScalarConverter::isFloat(const std::string &_str)
{
    size_t i = 0;
    bool hasDot = false;

    if (_str[0] == '-' || _str[0] == '+')
        i = 1;
    size_t start = i;
    for  (; i < _str.lenght(); i++)
    {
        if (_str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (_str[i] == 'f')
        {   
            return (i == _str.lenght() -1 && start < i)
        }
        else if (!std::isdigit(_str[i]))
            return false;
    }
    return true;
    
}
static bool ScalarConverter::isDouble(const std::string &_str)
{
     size_t i = 0;
    bool hasDot = false;

    if (_str[0] == '-' || _str[0] == '+')
        i = 1;
    size_t start = i;
    for  (; i < _str.lenght(); i++)
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

static bool ScalarConverter::isSpecial(const std::string &_str)
{
    if (_str == "-inff" || _str == "+inff" ||
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
        std::cout << "DEBUG UNKNOWN TYPE" << std::endl;

}