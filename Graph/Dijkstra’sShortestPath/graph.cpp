

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;
class Edge;
class Vertex {
public:
  string Name;
  bool Visited;
  double TotalLength;
  Vertex *SourceOfTotalLength;
  vector<Edge *> VertexLinks;

  Vertex() {}
  Vertex(string name) {
    Name = name;
    Visited = false;
    TotalLength = numeric_limits<double>::infinity();
    SourceOfTotalLength = nullptr;
  }
};

class Edge {
public:
  double Weight;
  Vertex *Source;
  Vertex *Target;

  Edge(Vertex *source, Vertex *target, double weight = 0) {
    Source = source;
    Target = target;
    Weight = weight;
  }
};

class Graph {

  int last_index = 0;
  vector<Vertex *> vertices; // A vector of vertices that make up the graph
public:
  Graph(vector<string> names) {
    for (const auto &name : names) {
      Vertex *vertex = new Vertex();
      vertex->Name = name;
      vertices.push_back(vertex);
      last_index++;
    }
  }

public:
  void AddEdges(int vertexIndex, int targets[], int length) {
    this->vertices[vertexIndex]->VertexLinks.resize(length);
    for (int i = 0; i < length; i++) {
      this->vertices[vertexIndex]->VertexLinks[i] =
          new Edge(this->vertices[vertexIndex], this->vertices[targets[i]]);
    }
  }

public:
  void AddEdges(int vertexIndex, int targets[], double weights[], int length) {
    this->vertices[vertexIndex]->VertexLinks.resize(length);
    for (int i = 0; i < length; i++) {
      this->vertices[vertexIndex]->VertexLinks[i] = new Edge(
          this->vertices[vertexIndex], this->vertices[targets[i]], weights[i]);
    }
  }

  void Dijkstra() {
    cout << "Dijkstra From Graph Class;" << endl;
    int numVertices = this->vertices.size();
    for (int i = 1; i < numVertices; i++) {
      vertices[i]->TotalLength = numeric_limits<double>::max();
    }

    Vertex *current_vertex;
    for (int i = 0; i < numVertices; i++) {
      current_vertex = vertices[i];
      vector<Edge *> destinations = current_vertex->VertexLinks;
      if (destinations.size() == 0)
        continue;

      Edge *current_edge;
      for (int j = 0; j < current_vertex->VertexLinks.size(); j++) {
        current_edge = destinations[j];
        double new_length = current_vertex->TotalLength + current_edge->Weight;
        if (new_length < current_edge->Target->TotalLength) {
          current_edge->Target->TotalLength = new_length;
          current_edge->Target->SourceOfTotalLength = current_vertex;
        }
      }
    }

    string path = vertices[numVertices - 1]->Name;
    Vertex *v = vertices[numVertices - 1];
    while (v->SourceOfTotalLength != NULL) {
      path = v->SourceOfTotalLength->Name + " - " + path;
      v = v->SourceOfTotalLength;
    }
    cout << vertices[numVertices - 1]->TotalLength << endl;
    cout << path << endl;

    this->restoreVertices();
  }

  void BFS() {
    cout << "BFS From Graph Class;\n";
    int v = vertices.size();
    queue<Vertex *> q;
    q.push(vertices[0]);
    vertices[0]->Visited = true;

    Vertex *current_vertex;
    vector<Edge *> destinations;
    while (!q.empty()) {
      current_vertex = q.front();
      q.pop();
      destinations = current_vertex->VertexLinks;
      for (const auto &destination : destinations) {
        if (!destination->Target->Visited) {
          q.push(destination->Target);
          destination->Target->Visited = true;
          cout << current_vertex->Name << " - " << destination->Target->Name
               << endl;
        }
      }
    }
    restoreVertices();
  }

  // Method to perform a Depth-First Search (DFS) on the graph
  void DFS() {
    cout << "DFS From Graph Class;\n";
    DFSRecursion(vertices[0]);
    restoreVertices();
  }

  // Helper method to restore all vertices to an unvisited state
  void restoreVertices() {
    for (const auto &vertex : vertices) {
      vertex->Visited = false;
    }
  }
  // Helper method for DFS recursion
  void DFSRecursion(Vertex *current_vertex) {
    current_vertex->Visited = true;
    vector<Edge *> destinations = current_vertex->VertexLinks;
    for (const auto &destination : destinations) {
      if (!destination->Target->Visited) {
        cout << current_vertex->Name << " - " << destination->Target->Name
             << endl;
        DFSRecursion(destination->Target);
      }
    }
  }
};
