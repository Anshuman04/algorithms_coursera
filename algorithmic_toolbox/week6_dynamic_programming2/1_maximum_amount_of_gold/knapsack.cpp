#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  // int current_weight = 0;
  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  // return current_weight;
  vector<vector<int>> resVec(W+1,vector<int> (w.size()+1,0));
	for(int i=0;i<W+1;i++){
		for(int j=0;j<w.size()+1;j++)
			{
				if(i==0 || j==0)
					resVec[i][j]=0;
				else if(w[j-1]<=i)
					resVec[i][j]= max(w[j-1]+resVec[i-w[j-1]][j-1],resVec[i][j-1]);
				else
					resVec[i][j]=resVec[i][j-1];
			}}
  return resVec[W][w.size()];

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
