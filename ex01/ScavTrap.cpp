#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap(){
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << YELLOW << "ScavTrap " << RESET << "Default constructor called for " << name_ << ".\n";
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name){
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << YELLOW << "ScavTrap " << RESET << "Default Parameterized constructor called for " << name_ << ".\n";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
    std::cout << YELLOW << "ScavTrap " << RESET << "Copy constructor called.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    std::cout << YELLOW << "ScavTrap " << RESET << "Copy assignment operator called.\n";
    if (this != &other) {
        this->ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << YELLOW << "ScavTrap " << RESET << "Destructor called for " << this->name_ << ".\n";
}

// ---------------------------------------------------------
// METHOD
// ---------------------------------------------------------
void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints_ > 0 && this->energyPoints_ > 0) {
        --this->energyPoints_;
        std::cout << YELLOW << "ScavTrap " << RESET << this->name_ << " attacks " << target << ", causing " << this->attackDamage_ << " points of damage!\n";
    } else {
        std::cout << YELLOW << "ScavTrap " << RESET << this->name_ << RED << " can't attack because it has no hit points or energy points left!\n" << RESET;
    }
}

void ScavTrap::guardGate(){
    if (this->hitPoints_ > 0) {
        std::cout << YELLOW << "ScavTrap " << RESET << this->name_ << " is now in Gate keeper mode.\n";
    } else {
        std::cout << YELLOW << "ScavTrap " << RESET << this->name_ << RED << " cannot enter Gate keeper mode because it is already dead...\n" << RESET;
    }
}
