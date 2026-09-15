#include "FragTrap.hpp"
#include <iostream>

int main(){
    std::cout << "\n" << AQUA << "[親: ClapTrap]\n" << RESET ORANGE << "[子: FragTrap]\n" << RESET;

    std::cout << "\n========== [1] キャラクターの作成 ==========" << AQUA << "[親: ClapTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET << "\n";
    FragTrap chikawa("chikawa");

    //子クラスの初期化が適用されているか
	std::cout << "\n初期化時の期待値：100,100,30\n";
	chikawa.showStatus();

	std::cout << "\n========== [2] 攻撃attack()のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET << "\n";
    std::cout << "\n親クラスのattack messageが出る\n";
    chikawa.attack("hachiware");
    chikawa.showStatus();

    std::cout << "\n========== [3] 親クラスから引き継いだ機能のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET << "\n";
    // ダメージや回復は親の機能（ClapTrapの関数）がそのまま使えるか確認
    chikawa.takeDamage(30);
    chikawa.showStatus();
    chikawa.beRepaired(20);
    chikawa.showStatus();

    std::cout << "\n========== [4] FragTrap独自の機能のテスト ==========" << AQUA << "[親: ClapTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET << "\n";
    chikawa.highFivesGuys();

    std::cout << "\n========== [5] プログラム終了・破棄 (チェーニングの確認) ==========" << AQUA << "[親: ClapTrap]" << RESET ORANGE << "[子: FragTrap]" << RESET << "\n";
    return 0;
}
