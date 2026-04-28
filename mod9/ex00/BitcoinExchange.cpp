#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() : _dates(""), _value_num(0),_file_data(""){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy){*this = to_copy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
        this->_dates = original._dates;
        this->_value_num = original._value_num;
    }
    return (*this);
}
BitcoinExchange::BitcoinExchange(char *filename, char *datafile)
{
    fecthDataFromFile(datafile);
}


BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::fecthDataFromFile(char * file)
{
    std::ifstream f(file);
    std::string line;

    if (!f.is_open())
        throw BitcoinExchange::ReadFailed();
    std::getline(f,line);

    while (std::getline(f,line))
    {
        if(line.empty())
            continue;
         
        size_t pos= line.find(",");
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string ex_rate = line.substr(pos + 1);
            double num = std::atof(ex_rate.c_str());
            _data_map[date] = num;
        }
        else 
        {
            std::cout << "error en npos" << std::endl;
            f.close();
        }
        //std::stringstream ss (line);
        f.close();
    }
}




const char *BitcoinExchange::ReadFailed::what() const throw()
{
    return "Error: File failed ";
}


