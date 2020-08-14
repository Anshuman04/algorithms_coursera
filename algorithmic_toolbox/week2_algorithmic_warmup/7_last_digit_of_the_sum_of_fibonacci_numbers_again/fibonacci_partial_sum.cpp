#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibo_sum_digit(long long n)
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

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
	long long fromDigit;
	if (from == 0){
		fromDigit = 0;	
	}else{
		fromDigit = get_fibo_sum_digit(from - 1);
	}
	long long toDigit = get_fibo_sum_digit(to);
	if (toDigit < fromDigit)
	{
		toDigit = toDigit + 10;
	}
	return toDigit - fromDigit;


	
	// if (to <= 1)
	// {
	// 	return to;
	// }
	// long long debugPrev1 = 1;
	// long long debugPrev2 = 0;
	// long long fiboDebug, fiboSum {0};


	// long long prev1 = 1;
	// long long prev2 = 0;
	// long long fibo, sum {1};
	// long long prevSum = 0;
    // long long subDigit = -1;
    // long long totalDigit = -1;
	// vector <int> patternVect = {0, 1};

	// for (long long i = 2; i <= to; i++)
	// {
	// 	/*fiboDebug = debugPrev1 + debugPrev2;
	// 	debugPrev2 = debugPrev1;
	// 	debugPrev1 = fiboDebug;
	// 	fiboSum = fiboSum + fiboDebug;
	// 	std::cout << "DEBUG PRINTS: " << debugPrev2 << ", " << debugPrev1 << ", " << fiboDebug  << ", " << fiboSum << std::endl;*/



	// 	prevSum = sum;
	// 	fibo = (prev1 + prev2) % 100;
	// 	prev2 = prev1;
	// 	prev1 = fibo;
	// 	sum = (sum + fibo) % 10;
    //     if (i == (from - 1))
    //     {
    //         subDigit = sum;
    //     }
	// 	//std::cout << "DEBUG PRINTS: " << prev2 << ", " << prev1 << ", " << fibo  << ", " << sum << std::endl;
	// 	if ((prevSum==0) && (sum == 1))
	// 	{
	// 		long long patternLength = patternVect.size();
	// 		long long remainder = to % (patternLength - 1);
	// 		//std::cout << "DEBUG PRINTS 2: " << patternLength << ", " << remainder << ", " << patternVect.at(remainder) << std::endl;
	// 		//std::cout << "INTERNAL RETURN" << std::endl;
	// 		totalDigit = patternVect.at(remainder);
    //         if (subDigit == -1)
    //         {
    //             long long subRemainder = (from - 1) % (patternLength - 1);
    //             subDigit = patternVect.at(subRemainder);
    //         }
    //         break;

	// 	}else
	// 	{
	// 		patternVect.push_back(sum);
	// 	}
	// }
	// //std::cout << "EXTERNAL RETURN" << std::endl;
	// if (subDigit > totalDigit)
    // {
    //     totalDigit = totalDigit + 10;
    // }
    // return totalDigit - subDigit;
}

void test_solution()
{
	for (int i=10; i<100; i++)
	{
		long long opNaive = 0;
	}
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
	//test_solution();
}
