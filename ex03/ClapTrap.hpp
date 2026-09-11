#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

#define AQUA    "\033[38;5;51m"
#define YELLOW  "\033[33m"
#define ORANGE  "\033[38;5;208m"
#define PINK    "\033[38;5;206m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ClapTrap{
    protected:
        std::string name_;
        unsigned int hitPoints_;
        unsigned int energyPoints_;
        unsigned int attackDamage_;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void showStatus() const;
};

#endif

