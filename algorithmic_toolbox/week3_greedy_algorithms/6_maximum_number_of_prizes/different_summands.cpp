#include <iostream>
#include <vector>

using std::vector;

vector<long long> optimal_summands(int n) {
  vector<long long> prizeVect;
  long long newPrize = 0;
  long long remCandies = n;

  while (remCandies != 0)
  {
    newPrize = newPrize + 1;
    if (newPrize <= remCandies)
    {
      prizeVect.push_back(newPrize);
      remCandies = remCandies - newPrize;
    } else
    {
      break;
    }
    
  }
  long long prizes = prizeVect.size();
  prizeVect.at(prizes - 1) = prizeVect.at(prizes -1) + remCandies;
  //write your code here
  return prizeVect;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (long long i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
