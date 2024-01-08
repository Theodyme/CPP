#include <iostream>
#include <string>

class Contact
{
    private:
        int         index;
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string nbr;
        std::string secret;
    public:
        std::string get_firstname(void) const;
        std::string get_lastname(void) const;
        std::string get_nickname(void) const;
        std::string get_nbr(void) const;
        std::string get_secret(void) const;
        void        set_firstname(std::string fname);
        void        set_lastname(std::string lname);
        void        set_nickname(std::string nname);
        void        set_nbr(std::string nbr);
        void        set_secret(std::string secret);
}