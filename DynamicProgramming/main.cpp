#include <iostream>
#include <climits>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10;
// Define the labels and data for the graph
vector<string> labels = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
vector<vector<int>> _data = {
    {0, 2, 4, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 7, 4, 6, 0, 0, 0},
    {0, 0, 0, 0, 3, 2, 4, 0, 0, 0},
    {0, 0, 0, 0, 4, 1, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 4, 0},
    {0, 0, 0, 0, 0, 0, 0, 6, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  

struct state {
    string from, to;
    int cost;
};

//The time complexity of this code is O(n^2), where n is the length of the input _data array
//The space complexity is also O(n^2)
int main() {
    int n = _data.size();
  // Initialize the states vector to store the minimum cost and path to each node
    vector<state> states(n);
  // Set the last element of the states vector to have a cost of 0
    states[n - 1] = { "", "", 0 };

  // Iterate through each node, starting from the second to last node
    for (int i = n - 2; i >= 0; i--) {
      // Initialize the current state with a very large cost and no path
        states[i] = { labels[i], "", INT_MAX };
      // Iterate through each neighbor of the current node
        for (int j = i + 1; j < n; j++) {
          // If there is no edge between the current node and the neighbor, continue to the next neighbor
            if (_data[i][j] == 0) continue;
          // Calculate the new cost to reach the neighbor and add it to the cost of the neighbor's minimum path
            int newCost = _data[i][j] + states[j].cost;
          // If the new cost is smaller than the current minimum cost for the current node, update the current state
            if (newCost < states[i].cost) {
                states[i].to = labels[j];
                states[i].cost = newCost;
            }
        }
    }

    vector<string> path(1, "A");
    int i = 0, j = 0;
    while (i < states.size()) {
        if (states[i].from == path[j]) {
            path.push_back(states[i].to);
            j++;
        }
        i++;
    }

    cout << "Minimum Cost: " << states[0].cost << endl;
    cout << "Minimum path: ";
    for (string node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}