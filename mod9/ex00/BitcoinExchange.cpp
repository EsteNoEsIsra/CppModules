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
static void showData(std::map<std::string, double>da)
{
    std::map<std::string, double>::iterator it ;
    for(it=da.begin(); it != da.end(); ++it)
    {
        std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
    }

}

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
            isValidDate(date);
            std::string value = line.substr(pos +1);
            isValidValue(value);
            double n = std::atof(value.c_str());

            printLine(date ,n);
        }
        else
        {
            std::cerr << "Error: bad input" << std::endl;
        }

        
    }
    
}

void BitcoinExchange::printLine(std::string date ,double n)
{
    std::map<std::string, double>::iterator it;
    it = this->_data_map.find(date);

    if (it != this->_data_map.end())
    {
        double value = it->second;
        std::cout << date << " => " << n << " = " << n * value;
    }
    else
        std::cerr << "Error: printline" << std::endl;
}

bool BitcoinExchange::isValidDate(std::string date)
{


}

bool BitcoinExchange::isValidValue(std::string value)
{
    std::stringstream ss (value);
    double val;
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
    showData(_data_map); // para debugg 
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

