#include "header.h"

std::string get_name(std::string str) 
{
    std::string name;

    size_t posChar = str.find('.');
    if (posChar != std::string::npos)
    {
        name  = str.substr(0,posChar);
    }
    return name;
}

std::string get_ext(std::string str) 
{
    std::string name;
    size_t posChar = str.find('.');
    if (posChar != std::string::npos)
    {
        name  = str.substr(posChar);
    }
    return name;
}

void ft_error(std::string err)
{
    std::cout << err << std::endl;
    return ;
}

std::string replaceContent(std::string str ,std::string s1,std::string s2)
{
    std::string result;
    
    if (str == NULL || s1 == NULL || s2 == NULL)
        return NULL;

    size_t pos = str.find(s1);

    if (pos != std::string::npos)
    {
        std::string antes = str.substr(0, pos);  
        std::string despues = str.substr(pos + s1.length());
        result = antes + s2 + despues;
        return result;
    }

    return NULL;
}

int main(int ar, char **av)
{
    if (ar == 4)
    {
        std::ifstream file_in;
        std::ofstream file_out;

        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string extt = ".replace"
        std::stringstream buffer;

        file_in.open(av[1]);
        if(!file_in)
            ft_error("error opening the file");
        buffer << file_in.rdbuf();
        std::string str_readed = buffer.str();

        std::string fname = get_name(av[1]) + extt;
        
        file_out.open(fname)
        if (!file_out)
            ft_error("error opening the file");

        std::string fcontent = replaceContent(str_readed, s1,s2);
        if (fcontent == NULL)
            ft_error("error empty strings");


        file_out << fcontent;
        std::cout << fcontent << std::endl;

        file_out.close();
        file_in.close();
    }
    else 
        std::cout << "usage : ./sed_cpp <filename> <string_to_replace> <string_to_replace_with>" << std::endl;
    return (0);

}