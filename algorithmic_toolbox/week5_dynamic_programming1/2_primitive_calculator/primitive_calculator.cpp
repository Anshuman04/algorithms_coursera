#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_DP(int n) {
  std::vector<vector <int>> compVec;
  vector <int> seq1 = {1};
  vector <int> seq2 = {1, 2};
  vector <int> seq3 = {1, 3};
  //vector <int> seq4 = {1, 3, 4};
  compVec.push_back(seq1);
  compVec.push_back(seq2);
  compVec.push_back(seq3);
  //compVec.push_back(seq4);
  if (n <= compVec.size())
  {
    return compVec.at(n - 1);
  }
  //std::cout << "+++++++++++++++" <<std::endl;
  for (int i = 4; i <= n; i++)
  {
    int minIdx = i-2;
    //std::cout << "$$$$$$$$$$$$$$$" <<std::endl;
    if (i % 2 == 0){
      int tempIdx = (i / 2) - 1;
      if (compVec.at(tempIdx).size() <= compVec.at(minIdx).size()){
        //std::cout<< "##### " << compVec.at(tempIdx-1).size() << " < = " << compVec.at(minIdx).size() << std::endl;
        minIdx = tempIdx;
      }
    }
    if (i % 3 == 0){
      int tempIdx = (i / 3) -1;
      if (compVec.at(tempIdx).size() <= compVec.at(minIdx).size()){
        minIdx = tempIdx;
      }
    }
    //std::cout << "--------------" <<std::endl;
    vector <int> tempSeq = compVec.at(minIdx);
    tempSeq.push_back(i);
    compVec.push_back(tempSeq);
    //std::cout << "^^^^^^^^^^" <<std::endl;
  }
  //std::cout << "rrrrrrrrrr" <<std::endl;
  return compVec.at(n - 1);
}

// vector<int> optimal_sequence_DP2(int n) {
//   std::vector<vector <vector <int>>> compVec;
//   vector <vector <int>> seq1 = {{1}};
//   vector <vector <int>> seq2 = {{1, 2}};
//   vector <vector <int>> seq3 = {{1, 3}};
//   //vector <int> seq4 = {1, 3, 4};
//   compVec.push_back(seq1);
//   compVec.push_back(seq2);
//   compVec.push_back(seq3);
//   //compVec.push_back(seq4);
//   if (n <= compVec.size())
//   {
//     return compVec.at(n - 1).at(0);
//   }
//   //std::cout << "+++++++++++++++" <<std::endl;
//   for (int i = 4; i <= n; i++)
//   {
//     int minIdx = i-2;
//     //std::cout << "$$$$$$$$$$$$$$$" <<std::endl;
//     if (i % 2 == 0){
//       int tempIdx = (i / 2) - 1;
//       if (compVec.at(tempIdx-1).size() <= compVec.at(minIdx).size()){
//         minIdx = tempIdx;
//       }
//     }
//     if (i % 3 == 0){
//       int tempIdx = (i / 3) -1;
//       if (compVec.at(tempIdx-1).size() <= compVec.at(minIdx).size()){
//         minIdx = tempIdx;
//       }
//     }
//     //std::cout << "--------------" <<std::endl;
//     vector <int> tempSeq = compVec.at(minIdx);
//     tempSeq.push_back(i);
//     compVec.push_back(tempSeq);
//     //std::cout << "^^^^^^^^^^" <<std::endl;
//   }
//   //std::cout << "rrrrrrrrrr" <<std::endl;
//   return compVec.at(n - 1);
// }

int main() {
  int n;
  std::cin >> n;
  // for (int i = 1; i <= n; i++)
  // {
  //   vector <int> golden = optimal_sequence(i);
  //   vector <int> test = optimal_sequence_DP(i);
  //   if (golden.size() < test.size())
  //   {
  //     std::cout<< "Failed at " << i << std::endl;
  //     for (size_t i = 0; i < golden.size(); ++i) {
  //       std::cout << golden[i] << " ";
  //     }
  //     std::cout<< "" << std::endl;
  //     for (size_t i = 0; i < test.size(); ++i) {
  //       std::cout << test[i] << " ";
  //     }
  //   }
  // }
  vector<int> sequence = optimal_sequence_DP(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  return 0;
}
