/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-07 07:40:33
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-22 17:09:26
 */
#include <iostream>
#include <array>

constexpr int kWidth = 10;
constexpr int kHeight = 20;

using Grid = std::array<std::array<int, kWidth>, kHeight>;

// 打印游戏界面
void PrintGrid(const Grid& grid) {
  for (const auto& row : grid) {
    for (const auto& cell : row) {
      if (cell == 0) {
        std::cout << ".";
      } else {
        std::cout << "#";
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  Grid grid{};

  // 在游戏界面中间放置一个方块
  grid[kHeight / 2][kWidth / 2] = 1;

  PrintGrid(grid);
  return 0;
}
