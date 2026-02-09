#include "header.h"

/*
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
*/

/*
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
*/
void ft_error(std::string err)
{
    std::cout << err << std::endl;
    return ;
}

std::string replaceContent(std::string str ,std::string s1,std::string s2)
{
    std::string result = "";
    size_t pos = 0;
    size_t lastpos = 0;

    if (s1.empty())
        return str;

    while ((pos = str.find(s1, lastpos)) != std::string::npos)
    {
        result = result + str.substr(lastpos, pos - lastpos);
        result = result + s2;
        lastpos = pos + s1.length(); 
    }
     result = result + str.substr(lastpos);

    return result;
}

int main(int ar, char **av)
{
    if (ar == 4)
    {
        std::ifstream file_in;
        std::ofstream file_out;

        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string extt = ".replace";
        std::stringstream buffer;

        if (s1.empty())
        {
            ft_error("error empty s1");
            return 1;
        }
    
        file_in.open(av[1]);
        if(!file_in)
        {
            ft_error("error opening the file");
            return 1;
        }
        buffer << file_in.rdbuf();
        std::string str_readed = buffer.str();     
        std::string fname = std::string(av[1]) + extt;

        file_out.open(fname.c_str());
        if (!file_out)
        {
            ft_error("error opening the file");
            return 1;
        }      

        std::string fcontent = replaceContent(str_readed, s1,s2);

        file_out << fcontent;
        //std::cout << fcontent << std::endl;

        file_out.close();
        file_in.close();
    }
    else 
        std::cout << "usage : ./sed_cpp <filename> <string_to_replace> <string_to_replace_with>" << std::endl;
    return (0);

}