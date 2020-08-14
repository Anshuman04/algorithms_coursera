#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search_recursive(const vector<long long> a, int x, int left, int right) {
  if (left > right)
  {
    return -1;
  }
  int mid = (right + left) / 2;
  //std::cout<< "DEBUG_VALUES: " <<left << "  "<< right << " " << mid << std::endl;
  if (a.at(mid) == x)
  {
    //std::cout<< "SUCCESS" <<std::endl;
    //std::cout<< "DEBUG: " << mid << a.at(mid) << x << std::endl;
    return mid;
  }
  if (a.at(mid) > x)
  {
    return binary_search_recursive(a, x, left, mid - 1);
  }
  return binary_search_recursive(a, x, mid + 1, right);
  
}

int binary_search_iterative(const vector<long long> a, int x, int left, int right) {
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (a.at(mid) == x)
    {
      return mid;
    }
    if (a.at(mid) > x)
    {
      right = mid - 1;
    } else
    {
      left = mid + 1;
    }
  }
  return -1;
}

int linear_search(const vector<int> a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //std::cout<< "DEBUG: " << a
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  // for (int i = 0; i < m; ++i) {
  //   //replace with the call to binary_search when implemented
  //   std::cout << linear_search(a, b[i]) << ' ';
  // }
  //std::cout<< std::endl << "DEBUG OUTPUT: " << std::endl;
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_iterative(a, b[i], 0, a.size()-1) << ' ';
  }
}
