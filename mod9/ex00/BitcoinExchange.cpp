#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() : _file_data(""){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy){*this = to_copy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
        this->_file_data = original._file_data;
        this->_data_map = original._data_map;
    }
    return (*this);
}
BitcoinExchange::BitcoinExchange(const char *datafile) 
    : _file_data(datafile){}

BitcoinExchange::~BitcoinExchange()
{

}

//para debug 
// static void showData(std::map<std::string, double>da)
// {
//     std::map<std::string, double>::iterator it ;
//     for(it=da.begin(); it != da.end(); ++it)
//     {
//         std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
//     }

// }

void BitcoinExchange::exchangeBitcoins(const char* file_in)
{
    std::ifstream file(file_in);
    std::string line;

    if (!file.is_open())
        throw BitcoinExchange::ReadFailed();
    std::getline(file,line);

    while (std::getline(file,line))
    {
        if (line.empty())
            continue;
        size_t pos = line.find("|");
        if  (pos != std::string::npos)
        {
            std::string date = line.substr(0,pos);
            if (!isValidDate(date))
                continue;
            std::string value = line.substr(pos +1);
            if (!isValidValue(value))
                continue;
            double n = std::atof(value.c_str());

            printLine(date ,n);
        }
        else
        {
            ///// check
            std::cerr << "Error: bad input => " << line.substr(0,pos) << std::endl;
        }
    }
}

void BitcoinExchange::printLine(std::string date ,double n)
{
    std::map<std::string, double>::iterator it; 
    it = this->_data_map.lower_bound(date);

    if (it != this->_data_map.begin() && (it == this->_data_map.end() || it->first != date))
        --it;
    if(it != this->_data_map.end() && it->first <= date)
    {
        double value = it->second;
        std::cout << date << " => " << n << " = " << n * value << std::endl;
    }
    else
        std::cerr << "Error: NoData from that date" << std::endl;
}
static bool check_date(int y, int m, int d)
{
    if (d > 31 || d < 0)
    {
        std::cout << "Error: day in valid" << std::endl;
        return false;
    }
    if (m > 12 || m < 0)
    {
        std::cout << "Error: month in valid" << std::endl;
        return false;
    }
    if (y < 2009 || y < 0)
    {
        std::cout << "Error: year in valid" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(std::string date)
{
    size_t posFirts = date.find("-");
    size_t posSecond = date.find("-", posFirts + 1);
    if (posFirts != std::string::npos && posSecond != std::string::npos)
    {
        std::string s_year = date.substr(0,posFirts);
        std::string s_month = date.substr(posFirts+1 , posFirts - posSecond - 1);
        std::string s_day = date.substr(posSecond+1);

        int year = std::atoi(s_year.c_str());
        int month = std::atoi(s_month.c_str());
        int day = std::atoi(s_day.c_str());
        if (!check_date(year, month,day))
            return false;
    }
    else 
    {
        std::cerr << "Error: Invalid date" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(std::string value)
{
    std::stringstream ss (value);
    double val;
    if (!(ss >> val) || val < 0)
    {
        if (val < 0)
            std::cout << "Error: is not a positive number" << std::endl;
        else 
            std::cout << "Error: invalid Value" << std::endl;
        return false;
    }
    else if (val >= INT_MAX)
    {
        std::cout << "Error: too large value" << std::endl;
        return false;
    }

    return true;
// std::stringstream ss(parteValor);
//     int valor;
//     if (!(ss >> valor) || valor < 0) {
//         std::cout << linea << " (error: valor no válido)" << std::endl;
//         return;
 //   }
}


std::map<std::string , double>& BitcoinExchange::getMapcontainer(){ return (_data_map); }


void BitcoinExchange::fecthDataFromFile(const char * file)
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
    }
    f.close();
  //  showData(_data_map); // para debugg 
}

const char * BitcoinExchange::getFiledataName() { return (_file_data);}



const char *BitcoinExchange::ReadFailed::what() const throw()
{
    return "Error: READ failed ";
}

const char* BitcoinExchange::BadInput::what() const throw()
{
    return " ";
}

