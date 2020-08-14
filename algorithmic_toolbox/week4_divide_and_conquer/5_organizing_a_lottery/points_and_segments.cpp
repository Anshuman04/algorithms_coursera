#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
int maxIndex = -1;
int maxVotes = 0;

struct Point
{
  long long value;
  int index;
  int voteCount = 0;
};


struct Segment
{
  long long start, end;
  bool leftLimit = false;
  bool rightLimit = false;
};

bool comparePoints(Point refPt, Point testPt)
{
  if (refPt.value < testPt.value)
  {
    return true;
  }
  return false;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}


void votePoints(vector <Point> &pointsVec, long long lowVal, long long upVal, int left, int right)
{
  if (left > right)
  {
    return;
  }
  long long mid = (left + right) / 2;

  if ((lowVal <= pointsVec[mid].value) && (pointsVec[mid].value <= upVal))
  {
      // std::cout << "+++ HIT ++++" << std::endl;
      pointsVec[mid].voteCount = pointsVec[mid].voteCount + 1;
      if (maxIndex == -1)
      {
        maxIndex = pointsVec[mid].index;
        maxVotes = pointsVec[mid].voteCount;
      } else
      {
        // std::cout<< "======== Prev: " << pointsVec[maxIndex].voteCount << " POST: " << pointsVec[mid].voteCount << std::endl;
        if (mid == maxIndex){
          maxVotes = pointsVec[mid].voteCount;
        }
        if (pointsVec[mid].voteCount > pointsVec[maxIndex].voteCount)
        {
          maxIndex = pointsVec[mid].index;
          maxVotes = pointsVec[mid].voteCount;
        }
      }
      votePoints(pointsVec, lowVal, upVal, left, mid - 1);
      votePoints(pointsVec, lowVal, upVal, mid + 1, right);
      
  } else
  {
    if (lowVal > pointsVec[mid].value)
    {
      votePoints(pointsVec, lowVal, upVal, mid + 1, right);
    } else
    {
      votePoints(pointsVec, lowVal, upVal, left, mid - 1);
    }
    
  }
}


int main() {
  int n, m;
  vector <Point> pointsVec;
  vector <Segment> segmentsVec;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    Segment segObj = Segment();
    std::cin >> segObj.start >> segObj.end;
    segmentsVec.push_back(segObj);
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    Point pointObj = Point();
    std::cin >> pointObj.value;
    pointObj.index = i;
    pointsVec.push_back(pointObj);
  }
  std::sort(pointsVec.begin(), pointsVec.end(), comparePoints);

  for (size_t i = 0; i < segmentsVec.size(); i++)
  {
    votePoints(pointsVec, segmentsVec.at(i).start, segmentsVec.at(i).end, 0, pointsVec.size()-1);
  }

  vector <int> resVector(pointsVec.size(), 0);
  if (maxIndex != -1)
  {
    resVector.at(maxIndex) = maxVotes;
  }
  //use fast_count_segments
  // vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < resVector.size(); i++) {
    std::cout << resVector[i] << ' ';
  }
}
