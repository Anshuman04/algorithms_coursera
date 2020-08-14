#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

struct midPoints
{
  int mid1 = 0;
  int mid2 = 0;
};

void print_vector(vector<long long> vectorToPrint, const char* vecName){
	//std::cout << "ENTERED PRINTER" << std::endl;
	std::cout << vecName << " = ";
	for (int i = 0; i < vectorToPrint.size(); i++){
		std::cout << vectorToPrint.at(i) << " ";
	}
	std::cout << " " << std::endl;
	//std::cout << "EXIT PRINTER" << std::endl;
}

midPoints partition3(vector<long long> &a, int l, int r) {
  int x = a[l];
  int m1 = l;
  int m2 = l;
  //std::cout << "============= PARTITION CALLED ================" << std::endl;
  //std::cout << "LEFT = " << l << "; RIGHT = " << r << "; M1: " << m1 << ": M2: " << m2 <<std::endl;
  //print_vector(a, "INPUT: ");
  int count = 0;
  for (int i = (l + 1); i <= r; i++) {
    //print_vector(a, "INTERMIEDIATE: ");
    count = count + 1;
    //std::cout << "LOOP: " << count << "; M2= " << m2 <<std::endl;
    if (a[i] <= x) {
      m2++;
      swap(a[i], a[m2]);
      //some swap
    }
    // else if(a[i] == x){
    //   m2++;
    //   swap(a[i], a[m2]);
    // //some swap
    // }

    
      
    //std::cout << "LOOP: " << count << " ends; M2= " << m2 <<std::endl;
    //print_vector(a, "INTERMIEDIATE: ");
    }
  swap(a[l], a[m2]);
  m1 = m2;
  for (int i=0; i<m1; i++)
  {
    if (a[i] == x)
    {
      m1 = m1 - 1;
      swap(a[i], a[m1]);
    }
  }
   
  // (a[l], a[m2]);
  //swap(a[l], a[m1]);
  //print_vector(a, "OUTPUT: ");
  //std::cout << "M1 = " << m1 << "; M2 = " << m2 << std::endl;
  //std::cout << "=================== PARTITION EXIT =================" <<std::endl;
  midPoints midPointObj = midPoints();
  midPointObj.mid1 = m1;
  midPointObj.mid2 = m2;
  return midPointObj;
}

void randomized_quick_sort(vector<long long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m1, m2;
  midPoints midObj = partition3(a, l, r);

  //std::cout<< "Calling sort 1 from index: " << l << " to " << midObj.mid1-1 <<std::endl;
  randomized_quick_sort(a, l, midObj.mid1 - 1);
  //std::cout<< "Calling sort 2 from index: " << midObj.mid2+1 << " to " << r <<std::endl;
  randomized_quick_sort(a, midObj.mid2 + 1, r);
}

void testSolution(){
  bool result = true;
  while (result){
  int n = rand() % 10;
  vector <long long> a, b;
  for (int i=0; i < n; i++)
  {
      long long element = rand() % 100;
      a.push_back(element);
      b.push_back(element);
  }
  print_vector(a, "RAW_INPUT: ");
  randomized_quick_sort(a, 0, a.size() - 1);
  std::sort(b.begin(), b.end());
  for (int i=0; i < n; i++)
  {
      if (a[i] != b[i])
      {
        result = false;
        break;
        
      }
      
      
  }
  if (result == false)
  {
    std::cout<< "ERROR: " <<std::endl;
    print_vector(a, "Output: ");
    print_vector(b, "EXPECTED: ");
  }else
      {
        std::cout << "OK !" << std::endl;
      }

  }

}


//88 64 28 41 50 93 0 34 64
//0 28 34 41 50 64 64 88 93


int main() {
  
  //testSolution();
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
