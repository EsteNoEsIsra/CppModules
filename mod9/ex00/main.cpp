
#include "BitcoinExchange.h"


int main(int ar, char **argv) 
{
    if (ar != 2)
    {
        std::cout << "missing arguments" << std::endl;
        return 1;
    }


    std::map<std::string, int> dataMap;
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // 1. Leer la primera línea (cabecera) para s   altarla
    std::getline(file, line);

    // 2. Leer el resto de líneas
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Saltamos líneas vacías

        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        // Separamos por la coma
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            // 3. Convertir el string del valor a int (Estilo C++98)
            std::stringstream converter(rateStr);
            int rateValue;
            
            if (converter >> rateValue) 
            {
                dataMap[date] = rateValue;
            }
        }
    }

    file.close();

    // Comprobación: Mostrar los datos guardados en el map
    std::map<std::string, int>::iterator it;
    for (it = dataMap.begin(); it != dataMap.end(); ++it) {
        std::cout << "Fecha: " << it->first << " | Valor: " << it->second << std::endl;
    }

    return 0;
}