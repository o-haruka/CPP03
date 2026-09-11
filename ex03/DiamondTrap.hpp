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
        
        //両方の親が attack() を持っているため、曖昧さを回避
        //*attackには()をつけない
        using ScavTrap::attack;
};

#endif
