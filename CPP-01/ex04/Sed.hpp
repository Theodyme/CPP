 #pragma once
 
 #ifndef SED_HPP
 #define SED_HPP

 #include <string>

class Sed 
{
    private:
        std::string _infile;
        std::string _outfile;
    public:
        Sed(std::string filename);
        ~Sed();
        void    open_replace(std::string needle, std::string replace);
};

#endif