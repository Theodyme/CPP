#include <iostream>
#include <fstream>
#include <string>
#include "Sed.hpp"

Sed::Sed(std::string filename) : _infile(filename), _outfile(filename + ".replace")
{

}

void    Sed::open_replace(std::string needle, std::string replace)
{
    std::ifstream   input;
    std::ofstream   output;
    std::string     line;
    size_t             pos;

    input.open(this->_infile);

    if (!input.is_open())
    {
        std::cerr << "Couldn't open the input file!\n";
        return ;
    }

    if (std::getline(input, line, '\0'))
    {
        output.open(this->_outfile);
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