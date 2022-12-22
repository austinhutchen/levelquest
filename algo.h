#ifndef ALGO_H
#define ALGO_H
#include <iostream>
#include <vector>
using namespace std;
// common algorithms I use. Updated regularly
class algo {
  public:
  int binarysearch(vector<int> list, int target) {
    int first = 0;
    int last = list.size() - 1;
    while (first <= last) {
      int mid = (first + last) / 2;
      if (list[mid] == target) {
        return mid;
      } else if (list[mid] < target) {
        first = mid + 1;
      } else if (list[mid] > target) {
        last = mid - 1;
      }
    }
    return 0;
  }

  int miniDist(int distance[], bool Tset[]) // finding minimum distance
  {
    int minimum = INT_MAX, ind;

    for (int k = 0; k < 6; k++) {
      if (Tset[k] == false && distance[k] <= minimum) {
        minimum = distance[k];
        ind = k;
      }
    }
    return ind;
  }

  void DijkstraAlgo(int graph[6][6], int source) // adjacency matrix
  {
    int distance[6]; // // array to calculate the minimum distance for each node
    bool Tset[6]; // boolean array to mark visited and unvisited for each node
    for (int k = 0; k < 6; k++) {
      distance[k] = -1;
      Tset[k] = false;
    }
    distance[source] = 0; // Source vertex distance is set 0
    for (int k = 0; k < 6; k++) {
      int m = miniDist(distance, Tset);
      Tset[m] = true;
      for (int k = 0; k < 6; k++) {
        // updating the distance of neighbouring vertex
        if (!Tset[k] && graph[m][k] && distance[m] != -1 && distance[m] + graph[m][k] < distance[k])
          distance[k] = distance[m] + graph[m][k];
      }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++) {
      char str = 65 + k;
      cout << str << "\t\t\t" << distance[k] << endl;
    }
  }
  string lowercase(string input) {
    for (int x = 0; x < input.size(); x++) {
      if (input[x] >= 65 && input[x] <= 90) {
        input[x] += 32;
      } else {
        continue;
      }
    }
    // end of loop
    return input;
  }

  void reverseString(vector<char> &s) {
    char z;
    char k;
    int j = s.size() - 1;
    for (int i = 0; i < s.size() && j > i; i++, j--) {
      z = s[j];
      k = s[i];
      s[j] = k;
      s[i] = z;
    }
  }
char findchar(string &test,char &target){
  // bubble sort needs to first be performed on string for this to be practica;
 int first = 0;
    int last = test.size() - 1;
    while (first <= last) {
      int mid = (first + last) / 2;
      if (test[mid] == target) {
        return mid;
      } else if (test[mid] < target) {
        first = mid + 1;
      } else if (test[mid] > target) {
        last = mid - 1;
      }
    }
    return 0;
}
string sort(string &unsorted){
for(int i=0;i<unsorted.size();i++){
for(int k=0;k<unsorted.size();k++){
if(unsorted[k]>unsorted[k+1]){
  // if k is greater, it is towards the end of alphabet, so swap with the one in front
char n=unsorted[k];
unsorted[k]=unsorted[k+1];
unsorted[k+1]=n;
}
else{continue;}
}
}
return unsorted;
};
// sort a string in alphabetical order, least to greatest (use bubble sort)

};
#endif