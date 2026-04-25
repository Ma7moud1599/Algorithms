# Algorithms — C++ Implementations

A collection of classic computer science algorithms implemented in C++ from scratch. Each algorithm is organized in its own directory with a clean header/implementation/main split, making them easy to study and run independently.

## Algorithms Covered

### Dynamic Programming
| Algorithm | File |
|---|---|
| 0/1 Knapsack Problem | `DynamicProgramming/01KnapsackProblem/` |
| Longest Common Subsequence | `DynamicProgramming/LongestCommonSubsequence/` |

### Graph Algorithms
| Algorithm | File |
|---|---|
| Breadth-First Search (BFS) | `Graph/BreadthFirstSearch/` |
| Depth-First Search (DFS) | `Graph/DepthFirstSearch/` |
| Dijkstra's Shortest Path | `Graph/Dijkstra'sShortestPath/` |
| Minimum Spanning Tree (Prim's/Kruskal's) | `Graph/MinimumSpanningTree/` |

### Greedy Algorithms
| Algorithm | File |
|---|---|
| Huffman Encoding | `Greedy/Huffman/` |
| Fractional Knapsack | `Greedy/Knapsack/` |

### Sorting
| Algorithm | File |
|---|---|
| Merge Sort | `MergSort/` |

### Utilities
| Utility | File |
|---|---|
| Character Frequency Counter | `CharFreq/` |

## Project Structure

Each algorithm follows the same layout:

```
AlgorithmName/
├── AlgorithmName.h      # Class/struct declaration
├── AlgorithmName.cpp    # Implementation
└── main.cpp             # Driver: sample input & output
```

## Building & Running

Requirements: g++ with C++17 support.

```bash
# Example: compile and run Dijkstra's shortest path
cd "Graph/Dijkstra'sShortestPath"
g++ -std=c++17 -o main graph.cpp main.cpp
./main
```

Or use the VS Code tasks provided in `.vscode/tasks.json` to build with a single keystroke.

## Concepts Demonstrated

- Adjacency list and matrix graph representations
- Priority queues for greedy selection
- Memoization vs tabulation in DP
- Divide-and-conquer (Merge Sort)
- Huffman tree construction and binary encoding

## License

MIT
