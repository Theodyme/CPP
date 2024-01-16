#include <iostream>
#include <fstream>
#include <string>
#include "Sed.hpp"

Sed::Sed(std::string filename) : _infile(filename), _outfile(filename + ".replace")
{

}

Sed::~Sed()
{

}

void    Sed::open_replace(std::string needle, std::string replace)
{
    std::ifstream   input(this->_infile.c_str());
    std::string     line;
    size_t             pos;

    if (!input.is_open())
    {
        std::cerr << "Couldn't open the input file!\n";
        return ;
    }

    if (std::getline(input, line, '\0'))
    {
        std::ofstream   output(this->_outfile.c_str());
        pos = line.find(needle);
        while (pos != std::string::npos)
        {
            line.erase(pos, needle.size());
            line.insert(pos, replace);
            pos = line.find(needle);
        }
        output << line;
        output.close();
    }
    else
    {
        std::cerr << "File is empty.\n";
        input.close();
        return ;
    }
    input.close();    
    return ;
}