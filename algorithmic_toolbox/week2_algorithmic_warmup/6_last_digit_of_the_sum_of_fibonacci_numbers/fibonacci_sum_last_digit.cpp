#include <iostream>
#include <vector>

using std::vector;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
	if (n <= 1)
	{
		return n;
	}
	long long debugPrev1 = 1;
	long long debugPrev2 = 0;
	long long fiboDebug, fiboSum {0};


	int prev1 = 1;
	int prev2 = 0;
	int fibo, sum {1};
	int prevSum = 0;
	vector <int> patternVect = {0, 1};

	for (long long i = 2; i <= n; i++)
	{
		/*fiboDebug = debugPrev1 + debugPrev2;
		debugPrev2 = debugPrev1;
		debugPrev1 = fiboDebug;
		fiboSum = fiboSum + fiboDebug;
		std::cout << "DEBUG PRINTS: " << debugPrev2 << ", " << debugPrev1 << ", " << fiboDebug  << ", " << fiboSum << std::endl;*/



		prevSum = sum;
		fibo = (prev1 + prev2) % 100;
		prev2 = prev1;
		prev1 = fibo;
		sum = (sum + fibo) % 10;
		//std::cout << "DEBUG PRINTS: " << prev2 << ", " << prev1 << ", " << fibo  << ", " << sum << std::endl;
		if ((prevSum==0) && (sum == 1))
		{
			long long patternLength = patternVect.size();
			long long remainder = n % (patternLength - 1);
			//std::cout << "DEBUG PRINTS 2: " << patternLength << ", " << remainder << ", " << patternVect.at(remainder) << std::endl;
			//std::cout << "INTERNAL RETURN" << std::endl;
			return patternVect.at(remainder);

		}else
		{
			patternVect.push_back(sum);
		}
	}
	//std::cout << "EXTERNAL RETURN" << std::endl;
	return sum;
}

void test_solution()
{
	for (long long i = 2; i<=200; i++)
	{
		std::cout << "================= LOOP " << i << std::endl;
		int opNaive, opFast;
		opNaive = fibonacci_sum_naive(i);
		opFast = fibonacci_sum_fast(i);
		std::cout<< "OP NAIVE: " << opNaive << std::endl;
		std::cout<< "OP FAST: " << opFast << std::endl;
		if (opNaive == opFast)
		{
			std::cout << "OK" << std::endl;
		} else
		{
			std::cout << "FAILURE" << std::endl;
			break;
		}
	}
}

int main() {
    long long n = 0;
    std::cin >> n;
    //test_solution();
    std::cout << fibonacci_sum_fast(n);
}
