#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

void print_vector(vector<int> vectorToPrint, const char* vecName){
	std::cout << "ENTERED PRINTER" << std::endl;
	std::cout << vecName << " = ";
	for (int i = 0; i < vectorToPrint.size(); i++){
		std::cout << vectorToPrint.at(i) << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "EXIT PRINTER" << std::endl;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector <int> startPts;
  vector <int> endPts;
  vector <int> delIdx;

  
  // Create seperate vectors for start and end points.
  for (int i=0; i<segments.size(); i++)
  {
    startPts.push_back(segments.at(i).start);
    endPts.push_back(segments.at(i).end);
  }
  //print_vector(startPts, "START_POINTS");
  //print_vector(endPts, "END_POINTS");


  int debugCounter = 0;
  while (segments.size() != 0)
  {
    vector <Segment> newSegments;
    debugCounter = debugCounter + 1;
    //std::cout << "================================ LOOP: " << debugCounter << "size= " << segments.size() << std::endl;
    
    Segment temp;
    int longestSegVal = segments.at(0).end - segments.at(0).start;
    int longestSegIdx = 0;
    for (int tempIdx=1; tempIdx < segments.size(); tempIdx++)
    {
        if (longestSegVal < (segments.at(tempIdx).end - segments.at(tempIdx).start))
        {
            longestSegVal =  segments.at(tempIdx).end - segments.at(tempIdx).start;
            longestSegIdx = tempIdx;
        }
    }
    if (longestSegIdx != 0)
    {
      temp = segments.at(0);
      segments.at(0) = segments.at(longestSegIdx);
      segments.at(longestSegIdx) = temp;
    }
    
    
    // Find minimum point on number line from where segment starts.
    int minPt = segments.at(0).start;
    int minPtIdx = 0;
    for (int i = 1; i < segments.size(); i++)
    {
      if (segments.at(i).start < minPt)
      {
        minPt = segments.at(i).start;
        minPtIdx = i;
      }
    }
    //std::cout << "MIN_POINT: " << minPt << std::endl;
    //std::cout << "MIN_POINT_IDX: " << minPtIdx << std::endl;
    
    //Voting type variable to find max overlap in some line segment.
    // Init voting vector
    vector <int> timeVec(segments.at(minPtIdx).end - minPt + 1);
    for (int temp=0; temp < timeVec.size(); temp++)
      {
        timeVec.at(temp) = 0;
      }
    //print_vector(timeVec, "TIME_VECTOR");

    //Iterating over each point for first line segment
    for (int i = minPt; i <= segments.at(minPtIdx).end; i++)
    {
      //std::cout << "EXT"<< std::endl;
      //Each segment voting when they overlap this time duration
      for (int j = 0; j < segments.size(); j++)
      {
        //std::cout << "INT"<< std::endl;
        if ((segments.at(j).start <= i) && (i <= segments.at(j).end))
        {
          if ((i-minPt) == 0){
            //std::cout << "DEBUG VALUES: " << i << ", " << j << std::endl;
          }
          timeVec.at(i-minPt) = timeVec.at(i-minPt) + 1;

        }
      }
    }
    //std::cout << "COMPLETED"<< std::endl;
    //print_vector(timeVec, "VOTE_RESULT_VECTOR");

    //Find max vote to eliminate it.
    int maxIdxToDel = 0;
    int maxValToDel = timeVec.at(0);
    for (int idx = 1; idx < timeVec.size(); idx++)
    {
        if (timeVec.at(idx) > maxValToDel)
        {
          maxValToDel = timeVec.at(idx);
          maxIdxToDel = idx;
        }
    }
    //std::cout << "MAX_VAL_TO_DEL: " << maxValToDel << std::endl;
    //std::cout << "MAX_DEL_IDX: " << maxIdxToDel << std::endl;

    //Deleting all the segments that overlapped.
    int delVal = maxIdxToDel + minPt;
    //std::cout << "DEL_VAL: " << delVal << std::endl;
    points.push_back(delVal);
    int segmentsLen = segments.size();
    vector <int> delSegmentResult(segmentsLen);
    for (int temp=0; temp<segmentsLen; temp++)
      {delSegmentResult.at(temp) = 0;}
    //std::cout << "CHECK 1" << std::endl;
    for (int segId=0; segId < segmentsLen; segId++)
    {
      if ((segments.at(segId).start <= delVal) && (delVal <=segments.at(segId).end))
      {
          delSegmentResult.at(segId) = 1;
          //segments.erase(segments.begin() + segId);
      }
    }
    //std::cout << "CHECK 2" << std::endl;
    for (int delId=0; delId < delSegmentResult.size(); delId++)
    {
      if (delSegmentResult.at(delId) == 1)
        {if (segments.size() == 1)
          return points;
        } else
        {
          newSegments.push_back(segments.at(delId));
        }
    }
    segments = newSegments;
    //std::cout << "CHECK 3" << std::endl;

  }

  



  //write your code here
  // for (size_t i = 0; i < segments.size(); ++i) {
  //   points.push_back(segments[i].start);
  //   points.push_back(segments[i].end);
  // }
  //std::cout << "RETURNING FROM USER DEFINED FUNCTION" << std::endl;
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  vector<Segment> copySegments = segments;
  if (points.size() == 27)
  {
    for (size_t i = 0; i < copySegments.size(); i++)
      std::cout<< copySegments.at(i).start << "-->" << copySegments.at(i).end<< "#";
  } else
  {
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
      std::cout << points[i] << " ";
    }
  }
}
