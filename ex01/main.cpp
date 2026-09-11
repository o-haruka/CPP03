#include "ScavTrap.hpp"
#include <iostream>

int main(){
    std::cout << "\n" << AQUA << "[親: ClapTrap]\n" << RESET YELLOW << "[子: ScavTrap]\n" << RESET;
    std::cout << "\n========== [1] キャラクターの作成 ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET << "\n";
    // コンストラクタ ClapTrap -> ScavTrap の順
    ScavTrap chikawa("chikawa");

    //子クラスの初期化が適用されているか
    chikawa.showStatus();

    std::cout << "\n========== [2] オーバーライドされた攻撃attack()のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET << "\n";
    chikawa.ClapTrap::attack("hachiware");
    chikawa.attack("hachiware");
    chikawa.showStatus();

    std::cout << "\n========== [3] 親クラスから引き継いだ機能のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET << "\n";
    // ダメージや回復は親の機能（ClapTrapの関数）がそのまま使えるか確認
    chikawa.takeDamage(30);
    chikawa.beRepaired(20);
    chikawa.showStatus();

    std::cout << "\n========== [4] ScavTrap独自の機能のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET << "\n";
    chikawa.guardGate();

    std::cout << "\n========== [5] プログラム終了・破棄 (チェーニングの確認) ==========" << AQUA << "[親: ClapTrap]" << RESET YELLOW << "[子: ScavTrap]" << RESET << "\n";
    return 0;
}
