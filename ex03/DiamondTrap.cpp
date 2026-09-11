#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

// ---------------------------------------------------------
// コンストラクタ
// ---------------------------------------------------------

DiamondTrap::DiamondTrap()
    :   ClapTrap("default_clap_name"),
        ScavTrap(),
        FragTrap(),
        name_("default")
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 30;
    std::cout << PINK << "DiamondTrap " << RESET << "Default constructor called.\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
    :   ClapTrap(name + "_clap_name"),
        ScavTrap(),
        FragTrap(),
        name_(name)
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 30;
    std::cout << PINK << "DiamondTrap " << RESET << "Parameterized constructor called for " << name_ << ".\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    :   ClapTrap(other),
        ScavTrap(other),
        FragTrap(other)
{
    std::cout << PINK << "DiamondTrap " << RESET << "Copy constructor called.\n";
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    std::cout << PINK << "DiamondTrap " << RESET << "Copy assignment operator called.\n";
    if(this != &other){
        ClapTrap::operator=(other); //!ポイント
        name_ = other.name_;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << PINK << "DiamondTrap " << RESET << "Destructor called for " << name_ << ".\n";
}

// ---------------------------------------------------------
// METHOD
// ---------------------------------------------------------
void DiamondTrap::whoAmI(){
    std::cout << PINK << "This is DiamondTrap [" << name_ 
              << "], and my ClapTrap name is [" << ClapTrap::name_ << "]!\n" << RESET;
}
