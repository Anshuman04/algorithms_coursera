#include <iostream>
#include <vector>

using std::vector;

// long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//   long long number_of_inversions = 0;
//   if (right <= left + 1) return number_of_inversions;
//   size_t mid = left + (right - left) / 2;
//   number_of_inversions += get_number_of_inversions(a, b, left, mid);
//   number_of_inversions += get_number_of_inversions(a, b, mid, right);
//   // write your code here
   

//   return number_of_inversions;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); i++) {
//     std::cin >> a[i];
//   }
//   vector<int> b(a.size());
//   std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
// }

// Implementing MERGE SORT HERE.

long long invCount = 0;


vector <int> mergeAndCount2(vector<int>vecB, vector<int> vecC)
{
  // std::cout<< "====== DANGER ====" << std::endl;
  vector <int> vecD;
  while ((!vecB.empty()) && (!vecC.empty()))
  {
      if (vecB.at(0) <= vecC.at(0))
      {
        vecD.push_back(vecB.at(0));
        vecB.erase(vecB.begin());
      } else
      {
        invCount = invCount + vecB.size();     // update count here count = count + vacB.size();
        vecD.push_back(vecC.at(0));
        vecC.erase(vecC.begin());
      }
  }
  if (!vecB.empty()){
    vecD.insert(vecD.end(), vecB.begin(), vecB.end());
  }
  if (!vecC.empty()){
    vecD.insert(vecD.end(), vecC.begin(), vecC.end());
  }
  return vecD;
}

vector <int> mergeNInversions(vector<int> &a, vector<int> &save, size_t left, size_t right)
{
  // std::cout<< "====== HIT ==== left: " << left << " right: " << right << std::endl;
  if (left == right)
  {
      vector <int> tempVec;
      tempVec.push_back(save.at(left));
      return tempVec;
  }
  int mid = (left + right) / 2;
  // std::cout<< "** left: " << left << " right: " << mid << std::endl;
  vector <int> vecB = mergeNInversions(a, save, left, mid);
  // std::cout<< "## left: " << mid+1 << " right: " << right << std::endl;
  vector <int> vecC = mergeNInversions(a, save, mid+1, right);
  a = mergeAndCount2(vecB, vecC);
  return a;  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> save;
  for (int bla = 0; bla < a.size(); bla++){
    save.push_back(a.at(bla));
  }
  mergeNInversions(a, save, 0, a.size() - 1);
  std::cout<<invCount<<std::endl;
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}