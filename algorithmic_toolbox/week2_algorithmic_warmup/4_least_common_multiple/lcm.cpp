#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long calcHCF(long long a, long long b){
    long long remainder = a % b;
	if (remainder == 0){
		return b;
	} else {
		calcHCF(b, remainder);
	}
}

long long lcm_fast(long long a, long long b, long long hcf){
	return (a / hcf) * b;
}

int main() {
  long long a, b, hcf;
  std::cin >> a >> b;
  if (a >= b){
  	hcf = calcHCF(a, b);
  } else {
  	hcf = calcHCF(b, a);
  }

  std::cout << lcm_fast(a, b, hcf) << std::endl;
  return 0;
}
