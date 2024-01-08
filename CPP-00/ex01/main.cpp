#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook   phonebook;
    std::string input;

    while(input != "EXIT")
    {
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            add();
        }
        if (input == "SEARCH")
        {
            search();
        }
    }
    return 0;
}