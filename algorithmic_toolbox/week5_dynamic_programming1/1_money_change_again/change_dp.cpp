#include <iostream>
#include <vector>

using std::vector;

int get_change(int m) {
  //write your code here
  vector <int> changeVec = {1, 2, 1, 1};
  if (m==0)
    return 0;
  if (m < changeVec.size()){
    return changeVec.at(m-1);
  }
  for (int i = 4; i < m; i++)
  {
    int d1 = changeVec.at(i - 1);
    int d3 = changeVec.at(i - 3);
    int d4 = changeVec.at(i - 4);
    int minIdx = i - 1;
    if (d3 < changeVec.at(minIdx)){
      minIdx = i - 3;
    }
    if (d4 < changeVec.at(minIdx)){
      minIdx = i - 4;
    }
    changeVec.push_back(changeVec.at(minIdx) + 1);
  }
  return changeVec.at(m-1);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
