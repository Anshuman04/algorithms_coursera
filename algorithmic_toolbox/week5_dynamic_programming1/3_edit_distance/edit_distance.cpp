#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
//using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int distMat[str1.size()+1][str2.size()+1] = {0};
  for (int i = 0; i<=str1.size(); i++){
    distMat[i][0] = i;
  }
  for (int j = 0; j<=str2.size(); j++){
    distMat[0][j] = j;
  }
  //vector <vector <int>> matchVec;
  
  for (int i = 1; i <=str1.size(); i++){
    for (int j = 1; j <= str2.size(); j++){
      int insertion = distMat[i][j-1] + 1;
      int deletion = distMat[i-1][j] + 1;
      int match = distMat[i-1][j-1];
      int misMatch = distMat[i-1][j-1] + 1;
      if (str1[i-1] == str2[j-1]){
        //vector <int> tempVec = {i-1, j-1};
        //matchVec.push_back(tempVec);
        distMat[i][j] = std::min(std::min(insertion, deletion), match);
      } else {
        distMat[i][j] = std::min(std::min(insertion, deletion), misMatch);
      }
  }}
  std::cout << "Length of first string: " << str1.size() << "--" << str1[0] << std::endl;
  std::cout << "Length of second string: " << str2.size() << "--" << str2[0] << std::endl;

  std::cout << "    ";
  for (int i = 0; i < str2.size(); i++)
    std::cout << str2[i] << " ";
  std::cout<< "" << std::endl;
  for (int i = 0; i <= str1.size(); i++){
    if (i > 0)
    std::cout << str1[i-1] << " ";
    else
    {
      std::cout << "  ";
    }
    
    for (int j = 0; j <= str2.size(); j++){
      std::cout << distMat[i][j] << " ";
    }
    std::cout<< "" << std::endl;
  }

  return distMat[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
