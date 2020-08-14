#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::stoi;

void print_vector(vector<int> vectorToPrint, const char* vecName){
	std::cout << "ENTERED PRINTER" << std::endl;
	std::cout << vecName << " = ";
	for (int i = 0; i < vectorToPrint.size(); i++){
		std::cout << vectorToPrint.at(i) << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "EXIT PRINTER" << std::endl;
}

bool isBig(int master, int test)
{
  vector <int> masterPool;
  vector <int> testPool;

  //std::cout << "MASTER: " << master << std::endl;
  //std::cout << "TEST: " << test << std::endl;

  while (master != 0)
  {
    int digit = master % 10;
    master = master / 10;
    masterPool.push_back(digit);
  }
  //print_vector(masterPool, "MASTER_POOL: ");
  while (test != 0)
  {
    int digit = test % 10;
    test = test /10;
    testPool.push_back(digit);
  }
  //print_vector(testPool, "TEST_POOL: ");
  vector <int> masterSeq = testPool;
  for (int i = 0; i < masterPool.size(); i++)
  {
    masterSeq.push_back(masterPool.at(i));
  }
  //print_vector(masterSeq, "MASTER_SEQ: ");
  vector <int> testSeq = masterPool;
  for (int i = 0; i < testPool.size(); i++)
  {
    testSeq.push_back(testPool.at(i));
  }
  //print_vector(testSeq, "TEST_SEQ: ");
  long long masterVal = 0;
  long long testVal = 0;
  long long mulFactor = 1;

  for(int idx=0; idx<testSeq.size(); idx++)
  {
    masterVal = masterVal + (mulFactor * masterSeq.at(idx));
    testVal = testVal + (mulFactor*testSeq.at(idx));
    mulFactor = mulFactor * 10;
  }
  //std::cout << "MASTER_VAL: " << masterVal << std::endl;
  //std::cout << "TEST_VAL: " << testVal << std::endl;
  if (masterVal > testVal)
  {
    //std::cout<< "MASTER WON" << std::endl;
    return true;
  } else
  {
    //std::cout<< "TEST WON" << std::endl;
    return false;
  }
  
}

long long largest_number(vector<int> a) {
  
  long long result=0;
  vector <int> finalSeq;

  
  int debugCounter = 0;
  while (a.size() != 0)
  {
    debugCounter = debugCounter + 1;
    //std::cout << "=========================== LOOP: " << debugCounter << std::endl;
    int maxVal = a.at(0);
    int maxValIdx = 0;
    for (int i=0; i<a.size(); i++)
    {
      if (isBig(maxVal, a.at(i)) == false)
      {
        maxVal = a.at(i);
        maxValIdx = i;
      }
    }
    finalSeq.push_back(a.at(maxValIdx));
    //print_vector(finalSeq, "FINAL_SEQ");
    if (a.size() == 1)
    {
      break;
    }else
    {
      a.erase(a.begin() + maxValIdx);
    }
  }

  vector <int> finalPool;
  for (int i = 0; i < finalSeq.size(); i++)
  {
    //std::cout<< "LOOP RUNNING" << std::endl;
    int number = finalSeq.at(i);
    vector <int> digitVec;
    while (number != 0)
    {
      digitVec.push_back(number % 10);
      number = number / 10;
    }
    for (int j=(digitVec.size()-1); j>=0; j--)
      finalPool.push_back(digitVec.at(j));
  }

  //print_vector(finalPool, "##### FINAL VECTOR: ");
  long long mulFactor = 1;
  for (int i = (finalPool.size() - 1); i >= 0; i--)
  {
    result = result + (finalPool.at(i) * mulFactor);
    mulFactor = mulFactor * 10;
  }
  //print_vector(a, "INPUT_VECTOR: ");
  // for (int i = 0; i < a.size(); i++)
  // {
  //   while (a[i] != 0)
  //   {
    
  //     availablePool.push_back(a[i] % 10);
  //     a[i] = a[i] / 10;
  //   }
  // }
  // //print_vector(availablePool, "AVAILABLE_POOL: ");
  // vector <int> sortedPool(availablePool.size());
  // sortedPool.at(sortedPool.size() - 1) = -1;
  // int idx = 0;
  // while (sortedPool.at(sortedPool.size() - 1) == -1)
  // {
  //   //print_vector(availablePool, "IN_LOOP: ");
  //   int maxVal = availablePool.at(0);
  //   int maxValIdx = 0;
  //   //std::cout<< "MAX VALUE: " << maxVal << std::endl;
  //   //std::cout << "MAX VALUE IDX: " << maxValIdx <<std::endl;
  //   for (int i = 0; i < availablePool.size(); i++)
  //   {
  //     if (maxVal < availablePool[i])
  //     {
  //       maxVal = availablePool[i];
  //       maxValIdx = i;
  //     }
  //   }
    
  //   sortedPool.at(idx) = maxVal;
  //   idx = idx + 1;
  //   if (availablePool.size() == 1)
  //     {break;}
  //   //print_vector(availablePool, "BEFORE_ERASE");
  //   availablePool.erase(availablePool.begin() + maxValIdx);
  //   //print_vector(availablePool, "AFTER_ERASE");
  // }
  // //print_vector(sortedPool, "SORTED_POOL: ");

  // long long mulFactor = 1;
  // for (int i = sortedPool.size() - 1; i >= 0; i--)
  // {
  //   result = result + mulFactor * sortedPool.at(i);
  //   mulFactor = mulFactor * 10;
  // }

  // //write your code here
  // // std::stringstream ret;
  // // for (size_t i = 0; i < a.size(); i++) {
  // //   //std::cout<< a[i];
  // //   for (int j =0 ; j < a[i].size(); j++)
  // //     {
  // //       std::cout<<  " # " << a[i][j];
  // //       const char * bla = a[i][j];
  // //       sum = sum + atoi(bla);
      
  // //     }
  // // }
  // // std::cout << "SUM: " << sum << std::endl;
  // // string result;
  // // ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
