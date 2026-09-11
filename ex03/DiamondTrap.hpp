#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
    private:
        std::string name_;
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        DiamondTrap(const std::string& name);

        void whoAmI();

        using ScavTrap::attack;
};

#endif
