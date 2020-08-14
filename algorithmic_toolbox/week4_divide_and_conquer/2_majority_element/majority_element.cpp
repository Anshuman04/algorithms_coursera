#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int customElement(vector<int> &a, int left, int right)
{
  vector <int> voteVec(1000000001, 0);
  int magicNum = a.size() / 2;
  for (int i=0; i<a.size(); i++)
  {
      voteVec.at(a.at(i)) = voteVec.at(a.at(i)) + 1;
      //std::cout << "DEBUG: " << voteVec.at(a.at(i)) << std::endl;
      if (voteVec.at(a.at(i)) > magicNum)
      {
        //std::cout << "SUCCESS: " << voteVec.at(a.at(i)) << std::endl;
        return 1;
      }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << customElement(a, 0, a.size()) << '\n';
}
