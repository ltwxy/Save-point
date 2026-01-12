#include <iostream>
#include <cstdlib> // 包含 rand() 和 srand()
#include <ctime>   // 包含 time()

using namespace std;

int main() {
    // 1. 播种：这行代码在整个程序里只要运行一次（通常放在 main 的最开头）
    srand(time(0)); 

    // 2. 生成随机数
    // 模拟丢三个骰子 << rand() % 6 + 1 << endl;
    cout  << rand() % 6 + 1 << endl;

    // 模拟一次攻击伤害 (50 - 100 之间)
    int damage = rand() % 51 + 50; // % 51 得到 0-50，再加 50 变成 50-100
    
    return 0;
}