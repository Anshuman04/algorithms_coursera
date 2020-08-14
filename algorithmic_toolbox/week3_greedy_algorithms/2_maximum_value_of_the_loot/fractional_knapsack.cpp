#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

void print_vector(vector<int> vectorToPrint, const char* vecName){
	std::cout << "ENTERED PRINTER" << std::endl;
	std::cout << vecName << " = ";
	for (int i = 0; i < vectorToPrint.size(); i++){
		std::cout << vectorToPrint.at(i) << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "EXIT PRINTER" << std::endl;
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  double length = values.size();
  double debugCoutner = 0;
  vector<double> ratio {};
  for (int i = 0; i < length; i ++)
  {
    ratio.push_back(values.at(i) / weights.at(i));
  }
  //print_vector(values, "VALUES");
  //print_vector(weights, "WEIGHTS");
  //print_vector(ratio, "RATIO");

  while (capacity > 0)
  {
    int maxIdx = 0;
    if (ratio.size() == 0)
    {
      break;
    }
    for (int i = 1; i < ratio.size(); i++)
    {
      if (ratio.at(maxIdx) < ratio.at(i))
      {
        maxIdx = i;
      }
    }
    //std::cout<< "MAX_INDEX: " << maxIdx << std::endl;
    double lootAvailable = weights.at(maxIdx);
    //std::cout<< "LOOT_AVAILABLE: " << lootAvailable << std::endl;
    //std::cout<< "CAPACITY: " << capacity << std::endl;
    if (capacity >= lootAvailable)
    {
      value = value + values.at(maxIdx);
      capacity = capacity - lootAvailable;
    } else
    {
      double remCapacityVal = ratio.at(maxIdx) * capacity;
      value = value + remCapacityVal;
      break;
    }
    //std::cout<< "VALUE: " << value << std::endl;
    //std::cout<< "NEW_CAPACITY: " << capacity << std::endl;
    ratio.erase(ratio.begin() + maxIdx);
    weights.erase(weights.begin() + maxIdx);
    values.erase(values.begin() + maxIdx);

  }

  // write your code here

  return value;
}

int main() {
  double n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  //std::cout.precision(7);
  std::cout << std::fixed << std::setprecision(3) << optimal_value << std::endl;
  return 0;
}
