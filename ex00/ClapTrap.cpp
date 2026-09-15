#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

ClapTrap::ClapTrap(): name_("default"), hitPoints_(10), energyPoints_(10), attackDamage_(0){
    std::cout << AQUA << "ClapTrap " << RESET << "Default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name): name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0){
    std::cout << AQUA << "ClapTrap " << RESET << "Default Parameterized constructor called for " << name_ << ".\n";
}

ClapTrap::ClapTrap(const ClapTrap& other): name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_){
    std::cout << AQUA << "ClapTrap " << RESET << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << AQUA << "ClapTrap " << RESET << "Copy assignment operator called\n";

    if(this != &other){
        this->name_ = other.name_;
        this->hitPoints_ = other.hitPoints_;
        this->energyPoints_ = other.energyPoints_;
        this->attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << AQUA << "ClapTrap " << RESET << "Destructor called for " << name_ << "\n";
}

// ---------------------------------------------------------
// METHOD
// ---------------------------------------------------------
// 変数名         | ゲームでの意味      | 詳細と課題のルール
// Name          | キャラクター名        | コンストラクタで引数として設定される名前。
// Hit points    | 体力 (HP)          | 初期値10。0になると死んで何もできなくなる。
// Energy points | 行動力 (MP/スタミナ) | 初期値10。攻撃や回復するたびに1ずつ減。0になると何もできなくなる。
// Attack damage | 攻撃力             | 初期値0。攻撃したときに相手に与えるダメージ量。

void ClapTrap::attack(const std::string& target){
    if(hitPoints_ > 0 && energyPoints_ > 0){
        --energyPoints_;
        std::cout << AQUA << "ClapTrap " << RESET << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!\n";
    }
    else
        std::cout << AQUA << "ClapTrap " << RESET << name_ << RED << " can't attack because it has no hit points or energy points left!" << RESET << "\n";
}

void ClapTrap::takeDamage(unsigned int amount){
    if(hitPoints_ > 0){
        if(amount > hitPoints_)
            hitPoints_ = 0;
        else
            hitPoints_-= amount;
        std::cout << AQUA << "ClapTrap " << RESET << name_ << " took " << amount << " points of damage! Current hit points: " << hitPoints_ << "\n";
    }
    else
        std::cout << AQUA << "ClapTrap " << RESET << name_ << RED << " is already dead..." << RESET <<"\n";
}

void ClapTrap::beRepaired(unsigned int amount){
    if(hitPoints_ > 0 && energyPoints_ > 0){
        --energyPoints_;

        if(amount > UINT_MAX - hitPoints_)
            hitPoints_ = UINT_MAX;
        else
            hitPoints_ += amount;

        std::cout << AQUA << "ClapTrap " << RESET << name_ << " repairs itself, regaining " << amount << " hit points! Current hit points: " << hitPoints_ << "\n";
    }
    else
        std::cout << AQUA << "ClapTrap " << RESET << name_ << RED << " can't repair itself because it has no hit points or energy points left!" << RESET << "\n";

}

void ClapTrap::showStatus() const{
    std::cout << BLUE << "===status of [[" << name_ << "]]====\n" << RESET;
    std::cout << BLUE << "hitPoints_: " << hitPoints_ << RESET << "\n";
    std::cout << BLUE << "energyPoints_: " << energyPoints_ << RESET << "\n";
    std::cout << BLUE << "attackDamage_: " << attackDamage_ << RESET << "\n\n";
}
