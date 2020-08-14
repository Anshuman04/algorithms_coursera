#include <iostream>
#include <vector>

using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

void print_vector(vector<long long> vectorToPrint, const char* vecName){
	std::cout << "ENTERED PRINTER" << std::endl;
	std::cout << vecName << " = ";
	for (int i = 0; i < vectorToPrint.size(); i++){
		std::cout << vectorToPrint.at(i) << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "EXIT PRINTER" << std::endl;
}

vector <long long> get_sliced_vector(vector <long long> testVector, int startIdx, int endIdx){
	vector <long long> finalVect {};
	for (int i = startIdx; i <=endIdx; i++){
		finalVect.push_back(testVector.at(i));
	}
	return finalVect;
}

vector<long long> calculate_period_vector(long long n,long long m){
	vector <long long> tempVector {0, 1};
	if (n <= 1){
		return tempVector;	//Handle this later.
	}
	long long prev1 = 1;
	long long prev2 = 0;
	long long fibo, rem;
	vector <long long> compareVect;
	vector <long long> compareVectDebug;
	for (long long i=2; i <= n+2; i++){
		//std::cout << "==================================================================="<< std::endl;
		//std::cout << "=====================LOOP = " << i << "==============================" << std::endl;
		fibo = (prev1 + prev2) % m;
		//std::cout << "FIBO = " << fibo << std::endl;
		if (i == n){
			vector <long long> otherVect;
			otherVect.push_back(fibo % m);
			return otherVect;
		}
		prev2 = prev1;
		prev1 = fibo;
		rem = fibo % m;
		//std::cout << "REM = " << rem << std::endl;
		tempVector.push_back(rem);
		//print_vector(tempVector, "TEMP_VECTOR");
		if (tempVector.size() % 2 == 0){
			int mid = tempVector.size() / 2;
			//long long first = tempVector.cbegin() + mid;
			//long long last = tempVector.cbegin() + tempVector.size();
			compareVect = get_sliced_vector(tempVector, mid, tempVector.size() - 1) ;
			//print_vector(compareVect, "COMPARE_VECT");
			compareVectDebug = get_sliced_vector(tempVector, 0, mid-1);
			//print_vector(compareVectDebug, "COMPARE_VECT_DEBUG");
			if (compareVect == compareVectDebug){
				//std::cout << "SUCCESS" << std::endl;
				return compareVect;
			}
		}
	}
	//std::cout<< "--------------------FAILED---------------------";
	//throw "ERROR in vector logic";
}

long long get_fibonacci_huge_fast(long long n,long long m){
    vector <long long> patternVect = calculate_period_vector(n, m);
	//std::cout<<"#######################################################################"<<std::endl;
	//print_vector(patternVect, "PATTERN_VECT");
	long long newDivisor = patternVect.size();
	//std::cout << "NEW_DIVISOR = " << newDivisor << std::endl;
	long long newRem = n % newDivisor;
	//std::cout << "NEW_REM = " << newRem << std::endl;
	//std::cout << "RESULT ===>>> " << patternVect.at(newRem) << std::endl;
	return patternVect.at(newRem);


}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << std::endl;
    /*int counter = 0;
    int op;
    vector <long long> resVec = {0, 1, 1, 2, 0, 2, 2, 1};
    for (int i = 16; i <=1000000; i++){
    	 op = get_fibonacci_huge_fast(i, 3);
	 if (resVec.at(counter) != op){
		 std::cout << "OP does not match for input: " << i << "\nEXPECTED OP = " << resVec.at(counter) << "\n OP = " << op << std::endl;
	 }
	 counter = counter + 1;
	 if ((counter % 8) ==0) {
	 	counter = 0;
	 }
	if ((i % 100000) == 0){
		std::cout << i / 100000 << "\% Loop completed." << std::endl;
	}
	
    }*/
}
