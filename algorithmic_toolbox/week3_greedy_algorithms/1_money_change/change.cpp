#include <iostream>
#include <vector>

using std::vector;

int get_change(int m) {
  //write your code here
  //std::cout << "INPUT MONEY: " << m << std::endl;
  int coins {0}, chngIdx {0};
  vector <int> diffChange {10, 5, 1};
  while (m > 0)
  {
    //std::cout << "COINS: " << coins << std::endl;
    coins = coins + (m / diffChange.at(chngIdx));
    m = m % diffChange.at(chngIdx);
    chngIdx = chngIdx + 1;
  } 
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
