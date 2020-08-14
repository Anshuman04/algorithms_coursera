#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
	int rem;
	rem = a % b;
	if (rem == 0){
	    return b;
	} else {
	    gcd_fast(b, rem);
	}
}

int main() {
  int a, b, gcd;
  std::cin >> a >> b;
  if (a>b){
      gcd = gcd_fast(a, b);
  } else {
      gcd = gcd_fast(b, a);
  }
  std::cout << gcd << std::endl;
  return 0;
}
