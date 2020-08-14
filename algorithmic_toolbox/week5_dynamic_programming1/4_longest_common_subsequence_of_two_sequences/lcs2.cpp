#include <iostream>
#include <vector>

using std::vector;
using std::string;

// int lcs2(vector<int> &a, vector<int> &b) {
//   //write your code here
//   //return std::min(std::min(a.size(), b.size()), c.size());
// }


int lcs2(vector <int> &str1, vector <int> &str2) {
  // write your code here
  int distMat[str1.size()+1][str2.size()+1] = {0};
  for (int i = 0; i<=str1.size(); i++){
    distMat[i][0] = i;
  }
  for (int j = 0; j<=str2.size(); j++){
    distMat[0][j] = j;
  }
  vector <vector <int>> matchVec;
  
  for (int i = 1; i <=str1.size(); i++){
    for (int j = 1; j <= str2.size(); j++){
      int insertion = distMat[i][j-1] + 1;
      int deletion = distMat[i-1][j] + 1;
      int match = distMat[i-1][j-1];
      int misMatch = distMat[i-1][j-1] + 1;
      if (str1[i-1] == str2[j-1]){
        vector <int> tempVec = {i-1, j-1, str1[i-1]};
        matchVec.push_back(tempVec);
        distMat[i][j] = std::min(std::min(insertion, deletion), match);
      } else {
        distMat[i][j] = std::min(std::min(insertion, deletion), misMatch);
      }
  }}

  if (matchVec.size() < 2){
    return matchVec.size();
  }

  vector <int> voteList(matchVec.size(), 1);
  for (int i = 0; i < matchVec.size(); i++){
    for (int j = i+1; j < matchVec.size(); j++){
      if ((matchVec[i][0] >= matchVec[j][0]) && (matchVec[i][1] >= matchVec[j][1]) && (matchVec[i][2] > matchVec[j][2])){
        //std::cout << "i > j HIT: " << matchVec[i][0] << matchVec[i][1]<< matchVec[j][0] << matchVec[j][1] << std::endl;
        voteList[i] += 1;
      } else if ((matchVec[i][0] <= matchVec[j][0]) && (matchVec[i][1] <= matchVec[j][1]) && (matchVec[i][2] < matchVec[j][2])){
        //std::cout << "j > i HIT: " << matchVec[i][0] << matchVec[i][1]<< matchVec[j][0] << matchVec[j][1] << std::endl;
        voteList[j] += 1;
      }
    }
  }
  // std::cout << "Length of first string: " << str1.size() << "--" << str1[0] << std::endl;
  // std::cout << "Length of second string: " << str2.size() << "--" << str2[0] << std::endl;

  // std::cout << "    ";
  // for (int i = 0; i < str2.size(); i++)
  //   std::cout << str2[i] << " ";
  // std::cout<< "" << std::endl;
  // for (int i = 0; i <= str1.size(); i++){
  //   if (i > 0)
  //   std::cout << str1[i-1] << " ";
  //   else
  //   {
  //     std::cout << "  ";
  //   }
    
  //   for (int j = 0; j <= str2.size(); j++){
  //     std::cout << distMat[i][j] << " ";
  //   }
  //   std::cout<< "" << std::endl;
  // }
  int maxVal = voteList[0];
  for (int i = 0; i < matchVec.size(); i++){
    if (voteList[i] > maxVal){
      maxVal = voteList[i];
    }
  }

  return maxVal;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}