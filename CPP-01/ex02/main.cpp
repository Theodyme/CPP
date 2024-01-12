#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF = str;

    std::cout << "> Welcome to CPP-01, ex02. No more zombie, it's too risky.\n";
    std::cout << "> Let's play with pointers and references!\n";
    std::cout << "\n";
    std::cout << "> We initialised a string. Here's the display of their adresses:\n";
    std::cout << "  string :    " << &str << "\n";
    std::cout << "  pointer :    " << &stringPTR << "\n";
    std::cout << "  reference :    " << &stringREF << "\n";
    std::cout << "\n";
    std::cout << "> Great! Here's the display of their values:\n";
    std::cout << "  string :    " << str << "\n";
    std::cout << "  pointer :    " << *stringPTR << "\n";
    std::cout << "  reference :    " << stringREF << "\n";
    return 0;
}