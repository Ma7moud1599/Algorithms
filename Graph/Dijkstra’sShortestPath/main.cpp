#include "graph.cpp"
#include "string"
#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<string> vertexNames = {"A", "B", "C", "D", "E","F", "G", "H", "I", "J"};
  Graph g(vertexNames);

  // g.AddEdges(0, {1, 2, 3}, {2, 4, 3});
  g.AddEdges(0, new int[]{1, 2, 3}, new double[]{2, 4, 3}, 3);

  g.AddEdges(1, new int[]{4, 5, 6}, new double[]{7, 4, 6}, 3);
  g.AddEdges(2, new int[]{4, 5, 6}, new double[]{3, 2, 4}, 3);
  g.AddEdges(3, new int[]{4, 5, 6}, new double[]{4, 1, 5}, 3);

  g.AddEdges(4, new int[]{7, 8}, new double[]{1, 4}, 2);
  g.AddEdges(5, new int[]{7, 8}, new double[]{6, 3}, 2);
  g.AddEdges(6, new int[]{7, 8}, new double[]{3, 3}, 2);

  g.AddEdges(7, new int[]{9}, new double[]{3}, 1);
  g.AddEdges(8, new int[]{9}, new double[]{4}, 1);

  g.Dijkstra();

  return 0;
}
