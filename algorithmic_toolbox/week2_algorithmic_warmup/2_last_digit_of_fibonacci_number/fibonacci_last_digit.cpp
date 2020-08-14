#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
	if (n <= 1){
		return n;
	}
	int prev1 = 1;
	int prev2 = 0;
	int newElement;
	for (int i=2; i<=n; i++){
		newElement = (prev1 + prev2) % 10;
		prev2 = prev1;
		prev1 = newElement;
	}
    return newElement;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
