#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
using namespace std;
class Graph {
public:
  Graph(vector<string> names);
  void addEdges(int vertexIndex, vector<int> targets);
  void BFS();


private:
  class Vertex;
  class Edge;

  void DFSRecursion(Vertex *current_vertex);
  void restoreVertices();

  int last_index = 0;
  vector<Vertex *> vertices; // A vector of vertices that make up the graph

  class Vertex {
  public:
    string name;  // The name of the vertex
    bool visited; // A flag to keep track of whether the vertex has been visited
    vector<Edge *> vertexLinks; // A vector of edges that connect the vertex to
                                // other vertices
  };

  class Edge {
  public:
    double weight;  // The weight of the edge (default value is 0)
    Vertex *source; // A pointer to the source vertex of the edge
    Vertex *target; // A pointer to the target vertex of the edge

    Edge(Vertex *source, Vertex *target, double weight = 0) {
      this->source = source;
      this->target = target;
      this->weight = weight;
    }
  };
};

#endif /* GRAPH_H */
