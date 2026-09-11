#include "ClapTrap.hpp"
#include <iostream>

int main(){
    std::cout << "\n========== [1] キャラクターの作成 ==========\n";
    ClapTrap chikawa("chikawa");
    ClapTrap hachiware("hachiware");
    ClapTrap clone(chikawa);

    std::cout << "\n<<initial status>>\n";
    chikawa.showStatus();
    hachiware.showStatus();
    clone.showStatus();

    std::cout << "\n========== [2] 基本アクションMETHOD ==========\n";
    chikawa.attack("hachiware");
    chikawa.showStatus();
    hachiware.takeDamage(0); // 初期攻撃値が0なので0を設定
    hachiware.showStatus();

    chikawa.beRepaired(5);
    chikawa.showStatus();

    std::cout << "\n========== [3] コピー代入演算子のテスト ==========\n";
    ClapTrap kurimanju("kurimanju");
    std::cout << "<kurimanju の初期状態>\n";
    kurimanju.showStatus();

    std::cout << "<chikawa の現在の状態を kurimanju にコピー(代入)>\n";
    kurimanju = chikawa; // コピー代入演算子呼ぶ
    std::cout << "[[chikawa]]\n";
    chikawa.showStatus();
    std::cout << "[[kurimanju]]\n";
    kurimanju.showStatus(); // HPやEPがchikawaと同じになっていればOK

    std::cout << "\n========== [4] 体力(HP)が0になるテスト ==========\n";
    //HP10->0 (0より小さくならないことを確認)
    hachiware.takeDamage(11);
    hachiware.showStatus();

    //死んだ状態で攻撃できない
    hachiware.attack("chikawa");
    hachiware.showStatus();

    //死んだ状態で回復できない
    hachiware.beRepaired(10);
    hachiware.showStatus();

    //すでに死んでいる
    hachiware.takeDamage(5);
    hachiware.showStatus();

    std::cout << "\n========== [3] エネルギ(EP)が0になるテスト ==========\n";
    for (int i = 0; i < 8; i++){
        chikawa.attack("hachiware");
    }
    chikawa.showStatus();

    //エネルギー0で攻撃できない
    chikawa.attack("hachiware");

    //エネルギー0で回復できない
    chikawa.beRepaired(10);

    return 0;
}
