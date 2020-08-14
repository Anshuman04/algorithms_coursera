#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    int max1Idx, max2Idx, temp;
    int n = numbers.size();
	if (numbers[0] >= numbers[1]){
		max1Idx = 0;
		max2Idx = 1;
	} else {
		max1Idx = 1;
		max2Idx = 0;
	
	}
	for (int i=2; i < n; i++){
		if (numbers[i] > numbers[max2Idx]){
			max2Idx = i;
			if (numbers[max2Idx] > numbers[max1Idx]){
				temp = max1Idx;
				max1Idx = max2Idx;
				max2Idx = temp;
			}
		}
	}
    
    long long max_product = numbers[max1Idx] * numbers[max2Idx];
    
    /*for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }*/

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
