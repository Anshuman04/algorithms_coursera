#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int length = stops.size();
    int presentLoc = 0;
    int presentIdx = 0;
    int stopsCount = 0;
    int debugCount = 0;
    while (presentLoc != dist)
    {
        debugCount = debugCount + 1;
        //std::cout<< "====================== LOOP: " << debugCount << std::endl;
        int prevLoc = presentLoc;

        for (int i=(length-1); i >=presentIdx; i--)
        {
            //std::cout << "I = " << i << std::endl;
            //std::cout << "PRESENT LOC = " << presentLoc << std::endl;
            //std::cout << "STOP_I = " << stops.at(i) << std::endl;
            if (stops.at(i)-presentLoc <= tank)
            {
                //std::cout << "REFUELING" << std::endl;
                presentLoc = stops.at(i);
                presentIdx = i;
                //std::cout << "PRESENT LOC = " << presentLoc << std::endl;
                if (presentLoc != dist)
                {
                    stopsCount = stopsCount + 1;
                }
                break;
            }
        }
        if (prevLoc == presentLoc)
        {
            //IMPOSSIBLE
            return -1;
        }

    }
    return stopsCount;
}


int main() {
    int distance = 0;
    cin >> distance;
    int capacity = 0;
    cin >> capacity;
    int numFuelStations = 0;
    cin >> numFuelStations;

    vector<int> stopDist(numFuelStations);
    for (size_t i = 0; i < numFuelStations; ++i)
        cin >> stopDist.at(i);

    cout << compute_min_refills(distance, capacity, stopDist) << "\n";

    return 0;
}
