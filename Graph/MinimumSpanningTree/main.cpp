#include <climits>
#include <iostream>

using namespace std;

int main() {

  char labels[] = {'1', '2', '3', '4', '5', '6'};
  double graph[6][6] = {
      {0, 6.7, 5.2, 2.8, 5.6, 3.6}, {6.7, 0, 5.7, 7.3, 5.1, 3.2},
      {5.2, 5.7, 0, 3.4, 8.5, 4.0}, {2.8, 7.3, 3.4, 0, 8, 4.4},
      {5.6, 5.1, 8.5, 8, 0, 4.6},   {3.6, 3.2, 4, 4.4, 4.6, 0}};

  int v = 6;
  int selected_edges_count = 0;
  bool selected[6] = {false};
  selected[0] = true;

  while (selected_edges_count < v - 1) {
    double min = INT_MAX;
    int temp_from = -1;
    int temp_to = -1;
    for (int i = 0; i < v; i++) {
      if (selected[i] == true) {
        for (int j = 0; j < v; j++) {
          if (selected[j] == false && graph[i][j] > 0 && graph[i][j] < min) {
            min = graph[i][j];
            temp_from = i;
            temp_to = j;
          }
        }
      }
    }

    selected[temp_to] = true;
    selected_edges_count++;

    // print the selected edge
    cout << labels[temp_from] << " - " << labels[temp_to] << " : "
         << graph[temp_from][temp_to] << endl;
  }

  return 0;
}
