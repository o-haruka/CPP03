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

// *最大のトリック：仮想継承時のコンストラクタ呼び出し
// 通常の継承であれば、親クラスのコンストラクタを呼べば、自動的にその親がおじいちゃんクラス（ClapTrap）を作ってくれます。
// しかし「仮想継承（virtual）」を使った場合、大元のクラス（ClapTrap）を重複させずに1つだけ作るために、一番末っ子である DiamondTrap が、大元の ClapTrap のコンストラクタを直接呼び出して初期化する責任を持つというC++の特別なルールが発生します。
// さらに課題文には、ClapTrap 側の名前は 渡された名前 + "_clap_name" にしなければならないという指定があります。
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
