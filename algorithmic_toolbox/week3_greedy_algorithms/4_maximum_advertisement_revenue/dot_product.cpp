#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  while(a.size() != 0)
  {
    int length = a.size();
    int maxA = a.at(0);
    int maxAidx = 0;
    int maxBidx = 0;
    int maxB = b.at(0);
    for (int i = 1; i < length; i++)
    {
      if (a.at(i) > maxA)
      {
        maxA = a.at(i);
        maxAidx = i;
      }
      if (b.at(i) > maxB)
      {
        maxB = b.at(i);
        maxBidx = i;
      }
    }
    result = result + (static_cast<long long>(maxA) * maxB);
    a.erase(a.begin() + maxAidx);
    b.erase(b.begin() + maxBidx);
  }
  // for (size_t i = 0; i < a.size(); i++) {
  //   result += ((long long) a[i]) * b[i];
  // }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
