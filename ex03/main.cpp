#include "DiamondTrap.hpp"
#include <iostream>

int main(){
    std::cout << "\n========== [1] DiamondTrapの作成 ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" <<  ORANGE << "[子: FragTrap]" << RESET PINK << "[孫: Diamond]" << RESET << "\n";
    // 仮想継承のおかげで、ClapTrapのコンストラクタが「1回だけ」呼ばれるか確認
    DiamondTrap usagi("usagi");
    //初期化100,50,30になってるか
    usagi.showStatus();

    std::cout << "\n========== [2] DiamondTrap独自method ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET PINK << "[孫: Diamond]" << RESET << "\n";
    // usagi と usagi_clap_name の両方が表示されるか確認
    usagi.whoAmI();

    std::cout << "\n========== [3] 各親クラスから引き継いだ機能の確認 ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET PINK << "[孫: Diamond]" << RESET << "\n";
    // 攻撃 (ScavTrapの attack が呼ばれるはず)
    usagi.attack("Enemy");

    // ScavTrapだけの機能
    usagi.guardGate();

    // FragTrapだけの機能
    usagi.highFivesGuys();

    std::cout << "\n========== [4] ダメージと回復の確認 ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET PINK << "[孫: Diamond]" << RESET << "\n";
    // HP(100)やEP(50)が正しく引き継がれているかのテスト
    usagi.takeDamage(50);
    usagi.beRepaired(20);

    std::cout << "\n========== [5] プログラム終了・破棄 ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET PINK << "[孫: Diamond]" << RESET << "\n";
    // 子から順番にデストラクタが呼ばれ、ClapTrapの破棄も「1回だけ」か確認

    return 0;
}
