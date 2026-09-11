#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap(){
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << ORANGE << "FragTrap " << RESET << "Default constructor called for " << name_ << ".\n";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name){
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << ORANGE << "FragTrap " << RESET << "Default Parameterized constructor called for " << name_ << ".\n";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
    std::cout << ORANGE << "FragTrap " << RESET << "Copy constructor called.\n";
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    std::cout << ORANGE << "FragTrap " << RESET << "Copy assignment operator called.\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << ORANGE << "FragTrap " << RESET << "Destructor called for " << this->name_ << ".\n";
}

// ---------------------------------------------------------
// METHOD
// ---------------------------------------------------------
void FragTrap::highFivesGuys(void){
    std::cout << ORANGE << "FragTrap " << RESET << this->name_ << " requests a high five!\n";
}
